#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, T, K;
  cin >> N >> T;
  K=0;
  vector<int> c(N);
  vector<int> t(N);
  for (int i=0; i<N; i++) {
    cin >> c.at(i) >> t.at(i);
  }
  for (int j=0; j<N; j++) {
    if (t.at(j)>T) {
      c.at(j)=5000;
      K=K+1;
    }
  }
  sort(c.begin(),c.end());
  if (K==N) {
    cout << "TLE" << endl;
  }
  else {
    cout << c.at(0) << endl;
  }
}