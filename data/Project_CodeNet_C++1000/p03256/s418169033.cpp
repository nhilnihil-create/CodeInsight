#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,rem[200007],u,v,col[200007],cnt[2][200007];
vector <int> edge[200007];
string s;
queue <int> q;
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) col[i]=s[i-1]-'A';
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		edge[u].pb(v);
		edge[v].pb(u);
	}
	for(int i=1;i<=n;i++){
		for(int v:edge[i]) cnt[col[v]][i]++;
		//cout<<cnt[0][i]<<" "<<cnt[1][i]<<endl;
		if(cnt[0][i]==0 || cnt[1][i]==0) rem[i]=1, q.push(i);
	}
	while(!q.empty()){
		int u=q.front();
		//cout<<u<<endl;
		q.pop();
		for(int v:edge[u]){
			if(rem[v]==1) continue;
			cnt[col[u]][v]--;
			if(cnt[col[u]][v]==0) rem[v]=1, q.push(v);
		}
	}
	for(int i=1;i<=n;i++){
		if(rem[i]==0) return cout<<"Yes", 0;
	}
	cout<<"No";
}
