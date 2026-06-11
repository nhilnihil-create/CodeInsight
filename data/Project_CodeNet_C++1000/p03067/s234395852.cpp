#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B,C;
  cin >>A >>B >>C;
  
  if(A>B){
    if(C>B){
      if(A>C){
        cout <<"Yes" <<endl;
        return 0;
      }
    }
  }
  else{
    if(C>A){
      if(B>C){
        cout <<"Yes" <<endl;
        return 0;
      }
    }
  }
  cout <<"No" <<endl;
  return 0;
}