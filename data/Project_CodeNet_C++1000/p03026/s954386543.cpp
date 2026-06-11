#include <bits/stdc++.h>
#define rep(a,n) for (ll a = 0; a < (n); ++a)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e9;

ll n;
ll id;
vector<ll>a,b,c,ans;
vector<bool>seen;
Graph g;

void dfs(ll x,ll &id){
    seen[x]=true;
    ans[x]=c[id];
    for(ll t:g[x]){
        if(seen[t])continue;
        id++;
        dfs(t,id);
    }
}

int main(){
    cin >> n;
    c.resize(n);
    g.resize(n);
    rep(i,n-1){
        ll a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,n)cin>>c[i];
    sort(c.begin(),c.end());
    ll s = 0;
    rep(i,n-1)s += c[i];
    cout << s << endl;
    ans.resize(n);
    seen.resize(n,false);
    reverse(c.begin(),c.end());
    id = 0;
    dfs(0,id);
    rep(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}
