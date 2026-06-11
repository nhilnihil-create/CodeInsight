#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L.at(i);
  }
  sort(L.begin(), L.end());
  int M = L.at(N - 1);
  int S = 0;
  for (int i = 0; i < N - 1; i++) {
    S += L.at(i);
  }
  if (S > M) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}