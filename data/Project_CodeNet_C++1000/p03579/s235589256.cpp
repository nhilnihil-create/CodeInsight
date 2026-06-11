#include<bits/stdc++.h>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> p2;
#define sz(a) ll(a.size())
ll vis[100005],col[100005];
void dfs(ll i,vector<vector<ll>> &v){
	vis[i]=1;
	for(ll j=0;j<sz(v[i]);j++)
		if(!vis[v[i][j]]){
			col[v[i][j]]=(col[i]^1);
			dfs(v[i][j],v);
		}
}
void solve(){
	ll n,m;
	cin>>n>>m;
	vector<vector<ll>> v(n+1);
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,v);
	for(ll i=1;i<=n;i++)
		for(ll j=0;j<sz(v[i]);j++)
			if(col[i]==col[v[i][j]]){
				cout<<(n*(n-1)/2)-m;
				exit(0);
			}
	ll res=0;
	for(ll i=1;i<=n;i++)
		if(col[i])
			res++;
	cout<<res*(n-res)-m;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
    #endif
    clock_t z=clock();
    ll qc=1;
    //cin>>qc;
    for(ll i=1;i<=qc;i++){
        solve();
    }
    debug("Total Time:%.4Lf\n",(ld)(clock()-z)/CLOCKS_PER_SEC);
}