#include <bits/stdc++.h>
using namespace std;

int main() {
  int i = 0;
  int N;
  string S;
  string X;
  
  cin >> N ;
  
  while(i < N){
    cin >> S;
    if(S == "Y"){
      X = "Four";
      break;
    }else{
      X = "Three";
    }
    i++;
  }
  cout << X << endl;
}
