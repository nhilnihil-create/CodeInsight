#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, X;
  X = 0;
  cin >> N;
  for (int i = 0; i<N ;i++){
  string C;
  cin >> C;
    if (C == "Y"){
    X = X + 1;
    }
  }
  if (X == 0){
  cout << "Three" << endl;
  }
  else if (X != 0){
  cout << "Four" << endl;
  }
}
