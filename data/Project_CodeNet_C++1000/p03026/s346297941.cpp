#include <bits/stdc++.h>
using namespace std;  
#define rep(i, a, b) for(ll i = a; i < b; i++)
#define Rep(i, a, b) for(ll i = a; i <= b; i++)
#define repr(i, a, b) for(ll i = b-1; i >= a; i--)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((ll)(v).size())
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
// const ll INF = 1LL << 60;
const ll INF = 100000000000;
#define pp pair<ll, pair<ll, ll>> 
// #define fi first
// #define se second
 
/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/
priority_queue<ll> pq;
Vl adj[10005];
int col[10005];
ll ans[10005];
ll n; 
#define white 0
#define black 1
ll sum = 0;

void bfs(){
    queue<ll> qu;
    qu.push(1);
    col[1] = black;
    while(!qu.empty()){
        ll u = qu.front(); qu.pop();
        // cout << "now : " <<  u << endl;
        ans[u] = pq.top(); pq.pop();
        rep(i, 0, sz(adj[u])){
            if(col[adj[u][i]]==black) continue;
            qu.push(adj[u][i]);
            col[adj[u][i]] = black;
        }
    }
    sum -= ans[1];
    co(sum);
    Rep(i, 1, n) cout << ans[i] << " \n"[i==n];
}

int main(){
    cin >> n;
    // 隣接リスト
    rep(i, 0, n-1){
        ll a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, 0, n){
        ll c; cin >> c;
        sum += c;
        pq.push(c);
    }
    // 隣接リストチェック
    // Rep(i, 1, n){
    //     cout << i << ": ";
    //     rep(j, 0, sz(adj[i])){
    //         cout << adj[i][j] << " ";
    //     }
    //     coel;
    // }
    bfs();

    return 0;
}
