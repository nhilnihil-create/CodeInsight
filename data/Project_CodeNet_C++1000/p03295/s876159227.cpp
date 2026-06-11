#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<int, int>> P(M);
  for (int i = 0; i < M; i++) cin >> P.at(i).second >> P.at(i).first;
  sort(P.begin(), P.end());
  int ans = 0, T = 1;
  for (int i = 0; i < M; i++) {
    if (T <= P.at(i).second) {
      ans++;
      T = P.at(i).first;
    }
  }
  cout << ans << endl;
}