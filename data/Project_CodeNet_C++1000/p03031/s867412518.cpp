#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> A(M);
  rep (i, M) {
    int k;
    cin >> k;
    rep (j, k) {
      int s;
      cin >> s;
      s--;
      A[i].push_back(s);
    }
  }
  vector<int> P(M);
  rep (i, M) cin >> P[i];

  ll ans = 0;
  rep (i, 1 << N) {
    map<int, bool> mp;
    rep (j, N) {
      if (i & 1 << j) {
	mp[j] = true;
      }
    }

    bool ok = true;
    for (int l = 0; l < A.size(); l++) {
      int cnt = 0;
      for (auto v : A[l]) if (mp[v]) cnt++;
      if (cnt % 2 == P[l]) continue;
      ok = false;
    }
    if (ok) ans++;
  }

  cout << ans << endl;
  return 0;
}
