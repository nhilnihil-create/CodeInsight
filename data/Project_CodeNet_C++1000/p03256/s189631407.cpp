#include <bits/stdc++.h>
#define pb push_back
#define REP(i, n) for (signed long long i = 0; i < (n); i++)
#define MOD 998244353
#define INF 98765431219876543
#define bitcnt(a) (ll) __builtin_popcount((a))
#define lb(a, b) lower_bound((a).begin(), (a).end(), (b))
#define ub(a, b) upper_bound((a).begin(), (a).end(), (b))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<string, string> PS;

vector<ll> g[214514];
vector<P> p;
ll vis[214514][3]; // 1-おとずれた 2-いまいってるとこ
ll n, m;
string s;

ll dfs(ll now, ll from, ll mae, ll kiten) {
  if (vis[now][from] == 1) {
    return 1;
  }
  // cout << now << " " << from << endl;
  if (from != 2 && (vis[now][2] == 2 || vis[now][1] == 2 || vis[now][0] == 2)) {
    // vis[now][from] = 3;
    // cout << now << " " << from << " " << mae << " " << kiten << endl;
    return 2;
  }
  if (vis[now][from] == 3) {
    return 2;
  }
  vis[now][from] = 2;
  bool b = 0, c = 0;
  for (auto &a : g[now]) {
    if (from == 2) {
      int res = dfs(a, s[now] - 'A', now, kiten);
      if (res == 2) {
        if (s[a] == 'A')
          b = 1;
        else
          c = 1;
      }
    } else if (from == 0 && s[a] == 'B') {
      int res = dfs(a, s[now] - 'A', now, kiten);
      if (res == 2) {
        vis[now][from] = 3;
        return 2;
      }
    } else if (from == 1 && s[a] == 'A') {
      int res = dfs(a, s[now] - 'A', now, kiten);
      if (res == 2) {
        vis[now][from] = 3;
        return 2;
      }
    }
  }
  vis[now][from] = 1;

  if (from == 2 && b == 1 && c == 1) {
    // cout << now << " aaa" << endl;
    return 2;
  }
  return 0;
}

int main() {

  cin >> n >> m >> s;

  REP(i, m) {
    ll a, b;
    cin >> a >> b;
    p.pb(P(a - 1, b - 1));
    g[a - 1].pb(b - 1);
    g[b - 1].pb(a - 1);
  }

  REP(i, n) {
    if (vis[i][2] == 0) {
      if (dfs(i, 2, 0, i) == 2) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }

  cout << "No" << endl;
}