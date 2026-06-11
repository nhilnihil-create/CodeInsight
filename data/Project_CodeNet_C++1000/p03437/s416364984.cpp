#include<bits/stdc++.h>
using namespace std;
int main(){
  
  int X;
  int Y;
  cin >> X >> Y;
  
  if(X % Y == 0){
    cout << "-1" << endl;
  }
  else{
    while(true){
      if(!(X % Y == 0)){
        cout << X << endl;
        break;
      }
      X = X * X;
    }
  }
  
}