#include <iostream>

/*
Problem Statement
Takahashi is a user of a site that hosts programming contests.
When a user competes in a contest, the rating of the user (not necessarily an integer) 
changes according to the performance of the user, as follows:

Let the current rating of the user be 
a
Suppose that the performance of the user in the contest is 
b
Then, the new rating of the user will be the avarage of 
a
 and 
b
For example, if a user with rating 
1
 competes in a contest and gives performance 
1000
, his/her new rating will be 
500.5
, the average of 
1
 and 
1000
.
Takahashi's current rating is 
R
, and he wants his rating to be exactly 
G
 after the next contest.
Find the performance required to achieve it.
*/

int aRating(int a, int b){
    return (2 * b) - a;
}

int main(){
    int r,g;
    std::cin>>r>>g;
    std::cout<<aRating(r,g);
    return 0;
}