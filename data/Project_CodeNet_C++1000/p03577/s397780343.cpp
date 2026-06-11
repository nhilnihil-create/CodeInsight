#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N=S.size();
  if (N==9) {
    cout << S.at(0) << endl;
  }
  else {
    for (int i=0; i<N-9; i++) {
      cout << S.at(i);
    }
    cout << S.at(N-9) << endl;
  }
}
