#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define rep(i, n) for(ll i=0; i<(ll)(n); i++)
#define repd(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=b-1; (ll)(a)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    ll n;   cin >> n;
    vector<vector<ll>> g(n);
    rep(i, n-1){
        ll a, b;    cin >> a >> b;
        a--;    b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<ll> cost(n, 0), c(n);
    rep(i, n)   cin >> c[i];
    sort(ALL(c), greater<ll>());
    queue<ll> que;
    que.push(0);
    ll i=0, res=0;
    cost[0] = c[i++];
    while(!que.empty()){
        ll v = que.front();  que.pop();
        for(auto nv: g[v]){
            if(0<cost[nv]) continue;
            cost[nv] = c[i++];
            que.push(nv);
            res += min(cost[nv], cost[v]);
        }
    }
    cout << res << endl;
    rep(i, n) cout << cost[i] << ' ';
}
