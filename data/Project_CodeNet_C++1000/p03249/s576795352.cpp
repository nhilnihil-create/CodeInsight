#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+2;
map<int,int> idx;
vector<pair<int,int> > ans;
int n,ar[N],sz[N],sz1[N],ar1[N];
vector<int> adj[N];
void dfs(int x,int p){
	sz[x]=1;
	for(int i:adj[x]){
		if(i!=p){
			dfs(i,x);
			sz[x]+=sz[i];
			sz1[x]+=sz1[i]+sz[i];
		}
	}
}
void dfs1(int x,int p){
	for(int i:adj[x]){
		if(i!=p){
			sz1[i]=sz1[x]+n-2*sz[i];
			dfs1(i,x);
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,i,j,k,l;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>ar[i];
		ar1[i]=ar[i];
		idx[ar[i]]=i;
		sz[i]=1;
	}
	sort(ar+1,ar+1+n);
	for(i=n;i>1;i--){
		k=idx[ar[i]]; j=ar[i]+2*sz[k]-n; l=idx[j];
		if(!l||j>=ar[i]){
			cout<<"-1";
			return 0;
		}
		adj[l].push_back(k);
		adj[k].push_back(l);
		sz[l]+=sz[k];
		ans.push_back({k,l});
	}
	dfs(1,1);
	dfs1(1,1);
	for(i=1;i<=n;i++){
		if(sz1[i]!=ar1[i]){
			cout<<"-1";
			return 0;
		}
	}
	for(i=0;i<ans.size();i++){
		cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
}