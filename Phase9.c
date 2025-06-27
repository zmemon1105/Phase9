#include <stdio.h> //Standard stdio library
#include <stdlib.h> //Standard stdlib library
#include <time.h> //Standard time library
#include <string.h> //Standard string library
#include <ctype.h> //Standard ctype library
#include "phase9.h"

int main() { //main function
welcomeScreen(); //call welcomeScreen function
#include <stdlib.h> //Include the stdlib.h header file
srand((unsigned int)time(NULL)); //random number generator)
playGame(); //call playGame function
return 0;
}

void welcomeScreen() { //function protype
printf("W W EEEEE L CCCC OOO M M EEEEE\n"); //prints the first line of the welcome logo
printf("W W E L C O O MM MM E\n"); //prints the second line of the welcome logo
printf("W W W EEEE L C O O M M M EEEE\n"); //prints the third line of the welcome logo
printf("WW WW E L C O O M M E\n"); //prints the fourth line of the welcome logo
printf("W W EEEEE LLLLL CCCC OOO M M EEEEE\n"); //prints the fifth line of the welcome logo
printf(" TTTTT OOO \n");
printf(" T O O\n");
printf(" T O O\n");
printf(" T O O\n");
printf(" T OOO\n");
printf("PPPP H H A SSSS EEEE 9999\n"); //prints the first line of the phase9 logo
printf("P P H H A A SS E 9 9\n"); //prints the second line of the phase9 logo
printf("PPPP HHHH AA AA SS EEE 9999\n"); //prints the third line of the phase9 logo
printf("P H H A A SS E 9\n"); //prints the fourth line of the phase9 logo
printf("P H H A A SSSS EEEE 99\n"); //prints the fifth line of the phase9 logo
printf("PHASE 9 PHASES\n\n");
printf("1. 2 sets of 3\n");
printf("2. 1 set of 3 + 1 run of 4\n");
printf("3. 1 set of 4 + 1 run of 4\n");
printf("4. 1 run of 7\n");
printf("5. 1 run of 8\n");
printf("6. 1 run of 9\n");
printf("7. 2 sets of 4\n");
printf("8. 1 set of 5 + 1 set of 2\n");
printf("9. 1 set of 5 + 1 set of 3\n\n");
}

void playGame() { //controls the game play
struct Player one; //characters are put up to size 20
struct Player two; //characters are put up to size 20
//int oneHand[HAND];
//int twoHand[HAND];
int turn=ZERO;
int deck[DECK];
int deckIdx=ZERO;
int choice = ZERO;
int currentPlayer = ONE;
int discardOrDraw = ZERO;
int pickUp = ZERO;
int playerDiscard = ZERO;
choice = displayMenu(); //call displayMenu function
while (choice != EXIT){
if(choice == PLAY)
{
  
printf("Player One, enter your name:\n"); //asks player one to enter their name
scanf("%s", one.playerName); //scans for player one's name
one.playerNum = ONE;
one.currentPhase = ONE;
one.wins = ZERO;
printf("Player Two, enter your name\n"); //asks player two to enter their name
scanf("%s", two.playerName); //scans for player two's name
two.playerNum = TWO;
two.currentPhase = ONE;
two.wins = ZERO;
printf("\n%s and %s let's play Phase 9!\n\n", one.playerName, two.playerName); //prints the name of the players
  
initializeDeck(deck); //call initializeDeck function
//printf("Phase 9 Deck:\n\n");
//displayDeck(deck);//call displayDeck function
shuffleDeck(deck);//call shuffleDeck function
//printf("\n\nPhase 9 Deck:\n\n");
//displayDeck(deck);//call displayDeck function
dealHand(deck, &deckIdx, one.playerHand);//call dealHand function
qsort(one.playerHand, HAND, sizeof(one.playerHand[ZERO]), comp);
dealHand(deck, &deckIdx, two.playerHand);//call dealHand function
qsort(two.playerHand, HAND, sizeof(two.playerHand[ZERO]), comp); //sorts the twoHand array
int discard = dealDiscard(deck, &deckIdx);//call dealDiscard function)
  
while (isGameOver(one, two)==FALSE){ //while loop
if(currentPlayer == one.playerNum){ //if statement
displayPhase(one.currentPhase);
displayPlayerHand(one.playerName, one.playerHand); //call displayPlayerHand function
printf("\nDiscard pile");//prints the discard pile
displaySingle(discard);
discardOrDraw = playerOption(one.playerName);//call playerOption function
if(discardOrDraw==DISCARD){//if statement
  printf("\n %s picked up the discard\n", one.playerName);//prints the player picked up the discard
  pickUp=discard;
  printf("\nNew card");//prints the new card
  displaySingle(pickUp);
}
 else if(discardOrDraw == DRAW) {
                        printf("%s drew from the deck", one.playerName);
                        pickUp = draw(deck, &deckIdx);
                        printf("\n\nNew card");
                        displaySingle(pickUp);
                    }
                    playerDiscard = discardCard(one.playerName, one.playerHand, pickUp);
                    updateHand(one.playerName, one.playerHand, playerDiscard, &discard, pickUp);
                    if(checkPhase(one) == TRUE) {
                        printf("\n%s completed their phase!\n", one.playerName);
                        updatePhase(&one);
                    }
                    else {
                        printf("\n%s did not complete the phase\n", one.playerName);
                    }
                    currentPlayer = two.playerNum;
                }
                else if(currentPlayer == two.playerNum) {
                    displayPhase(two.currentPhase);
                    displayPlayerHand(two.playerName, two.playerHand);
                    printf("\nDiscard pile");
                    displaySingle(discard);
                    discardOrDraw = playerOption(two.playerName);

                    if(discardOrDraw == DISCARD) {
                        printf("%s picked up the discard\n", two.playerName);
                        pickUp = discard;
                        printf("\nNew card");
                        displaySingle(pickUp);
                    }
else if(discardOrDraw == DRAW) {
                        printf("%s drew from the deck", two.playerName);
                        pickUp = draw(deck, &deckIdx);
                        printf("\n\nNew card");
                        displaySingle(pickUp);
                    }
                    playerDiscard = discardCard(two.playerName, two.playerHand, pickUp);
                    updateHand(two.playerName, two.playerHand, playerDiscard, &discard, pickUp);
                    if(checkPhase(two) == TRUE) {
                        printf("\n%s completed their phase!\n", two.playerName);
                        updatePhase(&two);
                    }
                    else {
                        printf("\n%s did not complete the phase\n", two.playerName);
                    }
                    currentPlayer = one.playerNum;
                }
                //turn++;
            }
            printf("\nGame is over\n");
            if(one.currentPhase > NINE) {
                printf("%s wins the game!\n", one.playerName);
                one.wins++;
            }
            else if(two.currentPhase > NINE) {
                printf("%s wins the game!\n", two.playerName);
                two.wins++;
            }
        }
        else if(choice == LEAD) {
            readLeaderboardFile();
        }
        else {
            exit(ZERO);
        }
        choice = displayMenu();
        deckIdx = ZERO;
        turn = ZERO;
    }
}

int displayMenu() { //displays the menu
int choice = ZERO; //sets choice to 0
int valid = FALSE;
while(!valid){
printf("\nSelect a menu option\n");
printf("1. Play Phase9\n");
printf("2. View Leaderboard\n");
printf("3. Exit Game\n");
scanf("%d", &choice);
if (choice !=PLAY && choice !=LEAD && choice!=EXIT) //if statement
{ //added EXIT option
valid=FALSE; //sets valid to FALSE
}
else { //else statement
valid=TRUE; //sets valid to TRUE
}
}
return choice; //returns choice
}
void initializeDeck(int deck[DECK]){ //function protype
int idx=ZERO; //sets idx to 0
for(int k=ZERO; k<EIGHT; k++){ //for loop
for(int u=ONE; u<=TWELVE; u++ ){ //for loop
deck[idx]=u; //sets deck to u
idx++; //increments idx
}
}
for(int r=ZERO; r<EIGHT; r++){ //for loop
deck[idx]=WILD; //sets deck to WILD
idx++;
}
for(int d=ZERO; d<FOUR; d++){ //for loop
deck[idx]=SKIP; //sets deck to SKIP
idx++;
}
}
void shuffleDeck(int deck[DECK]){ //function protype
int idx=ZERO;
for(idx=ZERO; idx<DECK; idx++){
int c=rand()%DECK; //random number generator
int card=deck[idx]; //sets card to deck
deck[idx]=deck[c]; //sets deck to deck
deck[c]=card; //sets deck to card
}
}
void displayDeck(int deck[DECK]){
int idx=ZERO;
for(idx=ZERO; idx<DECK; idx++){
printf("%d ",deck[idx]); //prints deck
}
printf("\n");
}
void dealHand(int deck[DECK], int *deckIdx, int playerHand[HAND]){
int idx=ZERO;
for(idx=ZERO; idx<HAND; idx++){ //for loop
playerHand[idx]=deck[*deckIdx]; //sets playerHand to deck
(*deckIdx)++;
}
}
void displayPlayerHand(char player[NAME], int playerHand[HAND]){
printf("\n%s's hand:\n\n", player);
printf("+----+----+----+----+----+----+----+----+----+----+\n");
printf("|    |    |    |    |    |    |    |    |    |    |\n");
printf("|");
for(int idx=ZERO; idx<HAND; idx++){
if(playerHand[idx]==WILD){
printf(" W |");
}
else if(playerHand[idx]==SKIP){
printf(" S |");
}
else{
printf("%3d |", playerHand[idx]);
}
}
printf("\n|    |    |    |    |    |    |    |    |    |    | \n");
printf("+----+----+----+----+----+----+----+----+----+----+\n");
}
int dealDiscard(int deck[DECK], int *deckIdx){
int discard = deck[*deckIdx];
(*deckIdx)++;
return discard;
}
void displaySingle(int discard){
printf("\n");
  printf("+----+\n");
  printf("|    |\n");
  if(discard==WILD){
    printf("|  W  |\n");//prints the WILD card
      }
  else if(discard==SKIP){
    printf("|  S   |\n");//prints the SKIP card
  }
  else{
    printf("| %3d|\n", discard);//prints the discard card
  }
printf("|    |\n");
printf("+----+\n");
}

void readLeaderboardFile(){
  char line[LINE];
  int fieldIdx=ZERO;
  char*data[DATA];
  FILE*fp=fopen("leaderboard.txt", "r");
printf("\n---Phase9 Leaderboard---\n");
printf("----------------------------\n");
printf("Position | Player | Wins\n");
printf("-------- -------- ----------\n");

if (fp==NULL){
    perror("Error opening file");
  return;
}
  while (fgets(line, LINE, fp)!=NULL){
    //fgets(line, LINE, fp);
    char*field=strtok(line, ",");
    field=trim(field);
    while (field!=NULL){
      data[fieldIdx]=malloc(strlen(field+1));
      strcpy(data[fieldIdx], field);
      field=strtok(NULL, ",");
      field=trim(field);
      fieldIdx++;
    }
  }
fclose(fp);
for (int i=ZERO; i<DATA; i+= FIELDS){
  printf("%5s %10s %8s\n", data[i], data[i + 1], data[i + 2]);
}
}
int playerOption(char player[NAME]){
int choice = ZERO;
int valid = FALSE;
while (valid==FALSE){
  printf("\n%s, Select a menu option\n", player);
  printf("1. Pick up discard\n");
  printf("2. Draw from deck\n");
  scanf("%d", &choice);

  if (choice!=DISCARD && choice!=DRAW){
    valid=FALSE;
  }
  else {
    valid=TRUE;
  }
}
return choice;
}

int draw(int deck[DECK], int *deckIdx){
  int card=deck[*deckIdx];
  (*deckIdx)++;
  return card;
}
int discardCard(char player[NAME], int playerHand[HAND], int pickUp){
  int choice=ZERO;
  int valid = ZERO;
  displayPlayerHand(player, playerHand);
  printf(" (1)  (2)  (3)  (4)  (5)  (6)  (7)  (8)  (9)  (10)");
  displaySingle(pickUp);
printf(" (11)\n");
  while (!valid){
  printf("Select a card to discard (1-11): ");
  scanf("%d", &choice);
  if(choice >= 1 && choice <= 11){
    valid = TRUE;
  }
  else {
    valid = FALSE;
  }
  }
  return choice;
}
void updateHand(char player[NAME], int playerHand[HAND], int discardIdx, int* discard, int newCard){
  if (discardIdx==ELEVEN){
    printf("\n%s selected the drawn card to discard, hand does not change\n", player);
    return;
  }
  else{
    int card=playerHand[discardIdx-ONE];
    playerHand[discardIdx-ONE]=newCard;
    //displayPlayerHand(player, playerHand);
    qsort(playerHand, HAND, sizeof(playerHand[ZERO]), comp);
    *discard=card;
    displayPlayerHand(player, playerHand);
    printf("Discarded card");
    displaySingle(*discard);
  }
}
int checkPhase (struct Player player){
  int sets = ZERO;//sets sets to 0
  int setsTwo = ZERO;//sets setsTwo to 0
  int runs = ZERO;//sets runs to 0
  switch (player.currentPhase){
    case ONE://if statement
    sets = countSets(player.playerHand, HAND, THREE);//sets sets to countSets function
    return sets >= TWO;//returns sets
    break;//breaks out of switch

    case TWO:
    sets = countSets(player.playerHand, HAND, THREE);
    runs = countRuns(player.playerHand, HAND, FOUR);
    return sets >= ONE && runs >= ONE;
    break;

    case THREE:
    sets = countSets(player.playerHand, HAND, FOUR);
    runs = countRuns(player.playerHand, HAND, FOUR);
    return sets >= ONE && runs>= ONE;
    break;

    case FOUR:
    runs = countRuns(player.playerHand, HAND, SEVEN);
    return runs >= ONE;
    break;

    case FIVE:
    runs = countRuns(player.playerHand, HAND, EIGHT);
    return runs >= ONE;
    break;

    case SIX:
    runs = countRuns(player.playerHand, HAND, NINE);
    return runs >= ONE;
    break;

    case SEVEN:
    sets = countSets(player.playerHand, HAND, FOUR);
    return sets >= TWO;
    break;

    case EIGHT:
    sets = countSets(player.playerHand, HAND, FIVE);
    setsTwo= countSets(player.playerHand, HAND, TWO);
    return sets >= ONE && setsTwo >= ONE;
    break;

    case NINE:
    sets = countSets(player.playerHand, HAND, FIVE);
    setsTwo = countSets(player.playerHand, HAND, THREE);
    return sets >= ONE && setsTwo >= ONE;
    break;

    default: 
    return 0;
    break;
  

  }
}


int countSets(int playerHand[HAND], int size, int setSize ){
int counts[THIRTEEN]={ZERO};
int setCount = ZERO;
for (int i=ZERO; i < size; i++){
if (playerHand[i]>= ONE && playerHand[i]<=TWELVE){
  counts [playerHand[i]-ONE]++;//sets counts to playerHand
}
for(int i = ZERO; i < THIRTEEN; i++){
  if(counts[i] >= setSize){
    setCount++;
  }
}
}
return setCount;
}

int countRuns(int playerHand[HAND], int size, int runSize){
  int runs=ZERO;
  for (int i=ZERO; i<size; i++){
    int currentRun = ONE;
    for (int h=i+1; h<size; h++){
      if(playerHand[h]== playerHand[i]+currentRun){
        currentRun++;
        if (currentRun == runSize){
          runs++;
          break;
        }
      }
    }
  }
  return runs;
}

void updatePhase(struct Player *player){
  if(player->currentPhase < TEN){
  player->currentPhase++;
  }

}


void displayPhase(int currentPhase){
  switch(currentPhase){
    case ONE:
    printf("\nCurrent phase: 2 sets of 3\n");
    break;
    case TWO:
    printf("\nCurrent phase: 1 set of 3 + 1 run of 4\n");
    break;
    case THREE:
    printf("\nCurrent phase: 1 set of 4 + 1 run of 4\n");
    break;
    case FOUR:
    printf("\nCurrent phase: 1 run of 7\n");
    break;
    case FIVE:
    printf("\nCurrent phase: 1 run of 8\n");
    break;
    case SIX:
    printf("\nCurrent phase: 1 run of 9\n");
    break;
    case SEVEN:
    printf("\nCurrent phase: 2 sets of 4\n");
    break;
    case EIGHT:
    printf("\nCurrent phase: 1 set of 5 + 1 set of 2\n");
    break;
    case NINE:
    printf("\nCurrent phase: 1 set of 5 + 1 set of 3\n");
    break;

  }
}
void displayLeaderboard(){
printf("\n---Phase9 Leaderboard---\n");
printf("----------------------------\n");
printf("Position | Player | Wins\n");
printf("-------- -------- ----------\n");
printf("1 Zuhra 34 |\n");
printf("2 Asma 30 |\n");
printf("3 Meli 27 |\n");
printf("4 Koko 25 |\n");
printf("5 Siham 19 |\n");
printf("6 Layla 15 |\n");
printf("7 Ameera 8 |\n");
}
int comp(const void *a, const void *b) //function protype
{
return (*(int *)a - *(int *)b); //returns the difference of a and b
}

  // trims leading and trailing white space
  char *trim(char *str)
{
  // check if the string is empty
  if (str == NULL || *str == '\0')
  {
  return str;
  }
  // trim leading white space
  char *start = str;
  while (isspace((unsigned char)*start))
  {
  start++;
  }
  // trim trailing white space
  char *end = str + strlen(str) - 1;
  while (end > start && isspace((unsigned char)*end))
  {
  end--;
  }
  // add the null terminator
  end[1] = '\0';
  // return the updated string
  return start;
  }

int isGameOver(struct Player playerOne, struct Player playerTwo) {
    int gameOver = FALSE;
    if(playerOne.currentPhase > NINE || playerTwo.currentPhase > NINE) {
           gameOver = TRUE;
    }
    else {
            gameOver = FALSE;
    }
    return gameOver;
}
