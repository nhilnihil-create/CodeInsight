//Krunal_Mathukiya
#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define li long int
#define pb push_back
#define mkp make_pair
#define nikalL return
#define chalavo continue
#define basHo break
#define umap unordered_map
#define vi vector<int>
#define fr(i,s,n) for(int i=s;i<=n;++i)
#define frr(i,s,n) for(int i=s;i>=n;--i)
#define jaldiKarNe ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
int n;
vi g[100005];
li dp[100005][2];
int vis[100005][2];
// last : was my parent black?
li fn(int node,int par,int last) {
	if(vis[node][last]) return dp[node][last];
	vis[node][last]=1;
	if(par && g[node].size()==1) {
		if(last) return dp[node][last]=1;
		else return dp[node][last]=2;
	}
	li b=1,w=1;
	for(auto child:g[node]) {
		if(child==par) continue;
		li black=0,white=0;
		white=fn(child,node,0);
		if(!last) black=fn(child,node,1);
		b=(b*black)%mod;
		w=(w*white)%mod;
	}
	return dp[node][last]=(b+w)%mod;
}
int main() {
	jaldiKarNe;
	cin>>n;
	fr(i,1,n-1) {
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	int leaf=-1;
	fr(i,1,n) {
		if(g[i].size()==1) {
			leaf=i;
			break;
		}
	}
	if(n==1) cout<<"2\n";
	else cout<<fn(leaf,0,0);
}