#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
const ll mod=1000000007;
const char nl='\n';

ll dist[100010]={0}, ord[100010], N;

void dfs1(vector<vector<ll> > &g, vector<bool> &vs, ll u){
    if(vs[u]) return;
    vs[u]=true;
    for(auto v:g[u])
        dfs1(g,vs,v);
    ord[N--]=u;
}

void solve(){
    ll i,j,k,l,m,n,u,v;
    cin>>n>>m;
    N=n-1;
    vector<vector<ll> > g(n+1);
    vector<bool> vs(n+1,false);
    for(i=0;i<m;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }
    for(i=1;i<=n;i++){
        if(!vs[i]) dfs1(g,vs,i);
    }

//    for(i=0;i<n;i++) cout<<ord[i]<<" ";cout<<nl;

    for(i=0;i<n;i++){
        u=ord[i];
        for(auto v:g[u]){
            dist[v]=max(dist[v],dist[u]+1);
        }
    }

    ll ans=0;
    for(i=1;i<=n;i++) ans=max(ans,dist[i]);
    cout<<ans<<nl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1,i=1;
//    cin >> t;
	while (t--)
	{
//	    cout<<"Case #"<< i++ <<": ";
		solve();
	}
	return 0;
}

