#include<iostream>
using namespace std;

int main(){
  int N, A, B;
  int S = 0;
  int res = 0;
  int ANS = 0;
  cin >>N >>A >>B;
  for(int i = 1; i <= N; ++i){
    S += (i%10);
    S += (i/10)%10;
    S += (i/100)%10;
    S += (i/1000)%10;
    S += (i/10000)%10;
    if(A <= S && S <= B) ANS +=i;
    S = 0;
  }
  cout << ANS <<endl;
}
