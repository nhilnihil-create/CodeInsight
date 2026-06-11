#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  A.push_back(1e9);
  int ans = 0;
  for (int i = 0, cnt = 1; i < N; i++) {
    if (A.at(i) != A.at(i + 1)) ans += cnt / 2, cnt = 1;
    else cnt++;
  }
  cout << ans << "\n";
}