#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int ans[N];
void sol(int n)
{
	if(n==1){ans[n]=1;return;}
	bool win=false;
	if(!ans[n-1])sol(n-1);
	if(ans[n-1]==2)win=true;
	if(n>2){
		if(!ans[n-2])sol(n-2);
		if(ans[n-2]==2)win=true;
	}if(win)ans[n]=1;
	else ans[n]=2;
}
vector<int>V[N];
int mx=0;
int dfs(int idx,int par)
{
	int fi=0,se=0;
	for(auto k:V[idx]){
		if(k==par)continue;
		int u=dfs(k,idx);
		if(u>=fi)se=fi,fi=u;
		else if(u>se)se=u;
	}
	mx=max(mx,fi+se+1);
	return fi+1;
}
int main()
{
	int n;scanf("%d",&n);
	sol(n);
	for(int i=0;i<n-1;i++){
		int u,v;scanf("%d%d",&u,&v);
		V[u].push_back(v);
		V[v].push_back(u);
	}dfs(1,-1);
//	for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
//	cout<<endl;
//	cout<<mx<<'\n';
	if(ans[mx]==1)cout<<"First\n";
	else cout<<"Second\n";
}
