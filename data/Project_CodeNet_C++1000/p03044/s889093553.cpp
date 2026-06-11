#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1'000'000'007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a-1; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define rALL(x) x.rbegin(), x.rend()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

vector<vector<pair<ll, ll>>> g;
vector<ll> color;
void dfs(ll v, ll p=-1, ll c=0){
    color[v] = c;
    for(auto x: g[v]){
        if(x.first==p) continue;
        if(0<=color[x.first]) continue;
        ll nc = c;
        if(x.second%2) nc = 1-nc;
        dfs(x.first, v, nc);
    }
}
int main(){
    ll n;   cin >> n;
    g.resize(n), color.assign(n, -1);
    rep(i, n-1){
        ll a, b, c;    cin >> a >> b >> c;
        a--, b--;
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    dfs(0);
    rep(i, n) cout << color[i] << endl;
    
}
