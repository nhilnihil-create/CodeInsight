#include <bits/stdc++.h>
using namespace std;

int main () {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> arr (n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort (arr.begin(), arr.end());
  vector< pair<int, int> > q;
  for (int i = 0; i < m; i++) {
    int foo, bar;
    cin >> foo >> bar;
    q.emplace_back(bar, foo);
  }
  sort (q.rbegin(), q.rend());
  int cur = 0;
  for (int i = 0; i < m; i++) {
    int tempo = q[i].second;
    while (tempo > 0 && cur < n) {
      arr[cur] = max (arr[cur], q[i].first);
      --tempo;
      ++cur;
    }
  }
  cout << accumulate (arr.begin(), arr.end(), 0LL) << '\n';
  return 0;
}
