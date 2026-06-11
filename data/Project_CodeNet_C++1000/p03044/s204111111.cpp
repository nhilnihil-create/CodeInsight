#include <bits/stdc++.h>
using ll = long long;
#define FOR(i, k, n) for(ll i = (k); i < (n); i++)
#define FORe(i, k, n) for(ll i = (k); i <= (n); i++)
#define FORr(i, k, n) for(ll i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(ll i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;

const int INF = 1001001001;

using P = pair<ll, ll>;

ll color[100005];
vector<ll> edge[100005];
map<P, ll> length;


void dfs(ll u, ll p = -1, ll len = 0){
  color[u] = len%2;
  for(auto v : edge[u]){
    if(p == v) continue;
    ll l = length[P(u, v)];
    dfs(v, u, len + l);
  }
}


int main(void){
  ll n;
  cin >> n;
  REP(i, n) color[i] = -1;
  REP(i, n-1){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge[a].emplace_back(b);
    edge[b].emplace_back(a);
    length[P(a, b)] = c;
    length[P(b, a)] = c;
  }
  dfs(0);
  REP(i, n) cout << color[i] << endl;
  return 0;
}