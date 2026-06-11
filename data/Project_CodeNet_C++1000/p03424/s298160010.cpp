#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, P, W, G, Y;
  cin >> N;
  P=0;
  W=0;
  G=0;
  Y=0;
  vector<char> S(N);
  for (int i=0; i<N; i++) {
    cin >> S[i];
  }
  for (int j=0; j<N; j++) {
    if (S[j]=='P') {
      P=P+1;
    }
    else {
      if (S[j]=='W') {
      	W=W+1;
      }
      else {
        if (S[j]=='G') {
          G=G+1;
        }
        else {
          Y=Y+1;
        }
      }
    }
  }
  if (P==0||W==0||G==0||Y==0) {
    cout << "Three" << endl;
  }
  else {
    cout << "Four" << endl;
  }
}