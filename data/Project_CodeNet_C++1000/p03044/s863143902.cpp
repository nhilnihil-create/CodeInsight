#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using pll = pair<ll,ll>;
using Graph = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i,l,r) for(ll i = (l); i <= (ll)(r); i++)
#define rep3(i,l,r) for(ll i = (l); i >= (ll)(r); i--)
#define dup(x,y) (((x)+(y)-1)/(y)) // x/yの除算の切り上げ
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int inf = 1001001001;
const ll INF = 1LL << 60;
const ll mod = 1000000007;
const ld pi = acos(-1);
 
int main(){
 
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<vector<ll>> to(n),cost(n);
    rep(i,n-1){
        ll a,b,w;
        cin >> a >> b >> w;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        cost[a].push_back(w);
        cost[b].push_back(w);
    }
    vector<ll> ans(n,-1);
    queue<ll> q;
    ans[0]=0;
    q.push(0);
    while(!q.empty()){
        ll v=q.front();
        q.pop();
        rep(i,to[v].size()){
            ll u=to[v][i];
            ll w=cost[v][i];
            if(ans[u]!=-1) continue;
            ans[u]=(ans[v]+w)%2;
            q.push(u);
        }
    }
    rep(i,n){
        cout << ans[i] << endl;
    }
}