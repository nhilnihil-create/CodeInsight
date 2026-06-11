#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
  int N, R, B;
  cin >> N;
  R=0;
  B=0;
  string s;
  cin >> s;
  for (int i=0; i<N; i++) {
    if (s[i]=='R') {
      R=R+1;
    }
    else {
      B=B+1;
    }
  }
  if (R>B) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}