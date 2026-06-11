#include<bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace _gnu_pbds;
#define vb __int128
#define ll long long
#define ld long double
#define full(a) a.begin(),a.end()
#define fr(i,a,b) for(ll i = a ; i < b ; i++)
#define stoink stack<ll>
#define quu queue<ll>
#define quee queue<pair<ll,ll>>
#define vec vector <ll>
#define vecd vector<ld>
#define vg vector<vector<ll> >
#define eg vector<pair<ll,ll>>
#define vgw vector<vector<pair<ll,ll> > >
#define pa pair<ll,ll>
#define pb push_back
#define ff first
#define ss second
#define pre 0.00000000000000000001
#define inf 100000000
#define mod (ll)(1e9 + 7)
#define endl '\n'
ll n;
vg graph;
ll dp[100005][2];
ll func(ll ver,ll par,ll col) {
    if(graph[ver].size() == 1 && ver != 1)
        return 1;
    if(dp[ver][col] != -1)
        return dp[ver][col];
    ll ans = 1;
    for(auto i : graph[ver]) {
        if(i == par)
            continue;
        if(col)
            ans = (ans * func(i,ver,0)) % mod;
        else
            ans = (ans * (func(i,ver,0) + func(i,ver,1)) % mod) % mod;
    }
    return dp[ver][col] = ans;
}
int main()
{	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n;
    graph.resize(n + 1);
    memset(dp,-1,sizeof(dp));
    fr(i,1,n) {
        ll u,v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    if(n == 1) {
        cout << "2";
        return 0;
    }
    cout << (func(1,0,0) + func(1,0,1)) % mod;
    return 0;
}	