#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main() {
  int N;

  cin >> N;
  vector< pair< pair< int, int >, int > > st(N);
  for(int i = 0; i < N; i++) {
    cin >> st[i].first.second >> st[i].first.first >> st[i].second;
  }
  sort(begin(st), end(st), [&](auto x, auto y) {
    return (x.first.first - y.first.second < y.first.first - x.first.second);
  });


  vector< int64 > dp(10002);
  int ret = 0;
  for(int i = 0; i < N; i++) {
    for(int j = st[i].first.first; j >= 0; j--) {
      int idx = min(j + st[i].first.second, 10001);
      dp[idx] = max(dp[idx], dp[j] + st[i].second);
    }
  }

  cout << *max_element(begin(dp), end(dp)) << endl;
}