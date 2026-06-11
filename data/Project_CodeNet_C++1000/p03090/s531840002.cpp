#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N; cin >> N;
  vector<pair<int, int>> ans;
  if (N % 2 == 0) {
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i + j == N + 1) continue;
        ans.push_back(make_pair(i, j));
      }
    }
  } else {
    for (int i = 1; i <= N - 1; i++) {
      ans.push_back(make_pair(i, N));
    }
    N--;
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        if (i + j == N + 1) continue;
        ans.push_back(make_pair(i, j));
      }
    }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < ans.size(); i++) {
    pair<int, int> p = ans[i];
    cout << p.first << ' ' << p.second << '\n';
  }
  return 0;
}