#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int N, A, B, a, b, c;
  cin >> N >> A >> B;
  a=0;
  b=0;
  c=0;
  vector<int> P(N);
  for (int i=0; i<N; i++) {
    cin >> P[i];
  }
  for (int j=0; j<N; j++) {
    if (P[j]<=A) {
      a=a+1;
    }
    else {
      if (P[j]<=B) {
        b=b+1;
      }
      else {
        c=c+1;
      }
    }
  }
  cout << min(min(a,b),c) << endl;
}