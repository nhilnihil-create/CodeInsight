#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<pair<int, int>> ans;
  int tmp = (N % 2 == 0) ? N : N-1;
  for (int i = 1; i < N; i++) {
    for (int j = i+1; j <= N; j++) {
      if (j == tmp) continue;
      ans.push_back(make_pair(i, j));
    }
    tmp--;
  }
  cout << ans.size() << endl;
  for (auto p : ans) cout << p.first << " " << p.second << endl;
}