#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const int INF = (1<<21);
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};


int main() {
  int N, K; cin >> N >> K;
  vector<int> v(N);
  for (int i = 0; i < N; ++i) cin >> v[i];
  int ans = 0;
  for (int l = 0; l <= K; ++l) {
    for (int r = 0; l + r <= K; ++r) {
      if (l + r > N) continue;
      int d = K - (l + r);
      vector<int> s;
      int now = 0;
      for (int i = 0; i < l; ++i) {
        now += v[i];
        s.push_back(v[i]);
      }
      for (int i = N-1; i >= N-r; i--) {
        now += v[i];
        s.push_back(v[i]);
      }
      sort(s.begin(), s.end());
      for (int i = 0; i < d; ++i) {
        if (i >= s.size()) break;
        if (s[i] > 0) break;
        now -= s[i];
      }
      ans = max(now, ans);
    }
  }
  cout << ans << endl;
}
