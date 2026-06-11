#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N;
  T=0;
  vector<int> L(N);
  for (int i=0; i<N; i++) {
    cin >> L.at(i);
  }
  sort(L.begin(),L.end());
  for (int j=0; j<N-1; j++) {
    T=T+L.at(j);
  }
  if (T>L.at(N-1)) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}