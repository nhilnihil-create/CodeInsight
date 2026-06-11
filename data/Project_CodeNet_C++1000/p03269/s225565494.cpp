#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define all(a) (a).begin(), (a).end()
#define sz(a) (a).size()
#define pb(a) push_back(a)
#define eb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
using namespace std;
using pii = pair<int, int>;
constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr double EPS = 1e-10;

struct edge {
  int t, c;
  edge() {}
  edge(int t, int c) : t(t), c(c) {}
};

int L;
int N, M;
vector<edge> g[20];

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> L;
  int r = 0;
  while ((1LL << r) <= L) r++;
  r--;
  rep(i, 0, r) {
    g[i].eb(i+1, 0);
    g[i].eb(i+1, (1LL << i));
  }
  int ng = 1LL << r;
  repr(i, r-1, 0) {
    if (ng + (1LL << i) <= L) {
      g[i].eb(r, ng);
      ng += 1LL << i;
    }
  }
  N = r+1;
  rep(i, 0, N) M += g[i].size();
  cout << N << " " << M << endl;
  rep(i, 0, N) {
    for (edge e : g[i]) {
      cout << i+1 << " " << e.t+1 << " " << e.c << endl;
    }
  }

  return 0;
}