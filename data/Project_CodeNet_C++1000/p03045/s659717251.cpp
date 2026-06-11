#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1000000007;

int n, m;
vector<vector<int>> to;
vector<vector<int>> z;
vector<int> cnt;

void dfs(int i) {
  for(int u: to[i]) {
    if (cnt[u]) continue;
    cnt[u] = 1;
    dfs(u);
  }
}

void solve() {
  cin >> n >> m;
  to.resize(n);
  z.resize(n);
  cnt.resize(n);
  rep(i,m) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    to[a].push_back(b);
    to[b].push_back(a);
    z[a].push_back(m);
    z[b].push_back(m);
  }

  int ans = 0;

  rep(i,n) {
    if (cnt[i]) continue;
    ans++;
    dfs(i);
  }
  cout << ans << endl;
}

int main() {
  solve();
  return 0;
}