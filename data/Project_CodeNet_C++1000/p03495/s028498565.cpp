#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K, A;
  cin >> N >> K;
  vector<int> cnt(N + 1);
  while (cin >> A) cnt.at(A)++;
  sort(cnt.rbegin(), cnt.rend());
  cout << N - accumulate(cnt.begin(), cnt.begin() + K, 0) << "\n";
}