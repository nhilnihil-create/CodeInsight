#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll mod=1e9+7;

vector<pll> to[100005];

vector<ll> color;

void dfs(ll v,ll p=-1,ll d=0){
    if(d%2==0){
        color[v]=1;
    }
    for(auto x:to[v]){
        if(x.fi==p) continue;
        dfs(x.fi,v,d+x.se);
    }
    return ;
}

int main()
{
    ll n;
    cin >> n;
    color.resize(n,0);
    rep(i,n-1){
        ll u,v,w;
        cin >> u >> v >> w;
        u--; v--;
        to[u].push_back(make_pair(v,w));
        to[v].push_back(make_pair(u,w));
    }
    dfs(0LL);
    rep(i,n){
        cout << color[i] << endl;
    }
    return 0;
} 