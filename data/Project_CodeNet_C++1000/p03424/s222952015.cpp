#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  string S;
  int P = 0;
  int W = 0;
  int G = 0;
  int Y = 0;
  cin >> N;

  // ここにプログラムを追記

  for (int i = 0 ; i < N ; i++) {
    cin >> S;
    if (S == "P") {
      P++;
    } else if (S == "W") {
      W++;
    } 
    if (S == "G") {
      G++;
    } 
    if (S == "Y") {
      Y++;
    } 
  }

  if ( P == 0 || W == 0 || G == 0 || Y == 0) {
    cout << "Three" << endl;
  } else {
    cout << "Four" << endl;
  }

}

