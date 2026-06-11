#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9 + 7;

void dfs(int s,int p,list<int>* adj,vector<ll>& w,vector<ll>& b){
	for(int c:adj[s]){
		if(c==p)
			continue;
		dfs(c,s,adj,w,b);

		w[s]*=(b[c]+w[c]);
		w[s]%=mod;

		b[s]*=w[c];
		b[s]%=mod;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;cin>>n;
	list<int>* adj=new list<int>[n+1];
	for(int i=1;i<n;i++){
		int a,b;cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> w(n+1,1);
	vector<ll> b(n+1,1);

	dfs(1,0,adj,w,b);
	int ans=(b[1]+w[1])%mod;
	cout<<ans<<endl;

	return 0;
}