#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);
const int MAX_C = 200000;

void add(ll &a, ll b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int main() {
  int n, pc = 0; cin >> n;
  vl cs;
  rep(i,n) {
    int c; cin >> c;
    if (c != pc) {
      pc = c; cs.pb(c);
    }
  }
  n = cs.size();

  vl pos(MAX_C+1,-1), dp(n,0);
  pos[cs[0]] = 0; dp[0] = 1;
  REP(i,1,n) {
    add(dp[i], dp[i-1]);
    if (pos[cs[i]] != -1) {
      add(dp[i], dp[pos[cs[i]]]);
    }
    pos[cs[i]] = i;
  }
  cout << dp[n-1] << endl;
  return 0;
}
