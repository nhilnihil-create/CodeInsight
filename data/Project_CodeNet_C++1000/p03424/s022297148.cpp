#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, X, Y;
  cin >> N;
  X = 1;
  for (int i = 0 ; i < N ; i++){
  string S;
  cin >> S;
  if (S == "P" || S == "W" || S == "G"){
  X = X * 1;
  }
  if (S == "Y"){
  X = X * 2;
  }
  }
  if (X % 2 == 1){
  cout << "Three" << endl;
  }
  else if (X % 2 == 0){
  cout << "Four" << endl;
  }
}
