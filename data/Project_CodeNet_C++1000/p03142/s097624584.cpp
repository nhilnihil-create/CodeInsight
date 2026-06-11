#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int , int >
#define F first
#define S second
#define int long long
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
using namespace std;
/// ya navid navid
const int N=2e5+100;
vector <int> g[N];
ll par[N];
ll vis[N];
ll ind[N];
int32_t main(){
    ll n,m;
    cin >> n >> m;
    for (int i=0;i<n+m-1;i++){
        ll u,v;
        cin >> u >> v;
        g[u].pb(v);
        ind[v]++;
    }
    ll root=0;
    queue <int> q;
    for (int i=1;i<=n;i++){
        if (ind[i]==0){
            root=i;
        }
    }
    q.push(root);
    while(q.size()){
        ll v=q.front();
        q.pop();
        for (int i=0;i<g[v].size();i++){
            ll u=g[v][i];
            ind[u]--;
            if (ind[u]==0){
                q.push(u);
                par[u]=v;
            }
        }
    }
    for (int i=1;i<=n;i++){
        cout << par[i] << endl;
    }

}
