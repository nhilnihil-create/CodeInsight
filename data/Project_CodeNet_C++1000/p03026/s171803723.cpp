#include<bits/stdc++.h>
using namespace std;
const int maxn=100100;
int n,a[maxn],res[maxn],ttt=0;
vector<int> ver[maxn];
long long ans=0;
inline void dfs(int x,int fat)
{
	res[x]=a[++ttt];
	for(int i=0;i<(int)ver[x].size();i++)
	{
		int y=ver[x][i];
		if(y==fat) continue;
		dfs(y,x);
	}
}
int main()
{
	cin>>n;
	for(int i=1,x,y;i<n;i++)
	{
		cin>>x>>y;
		ver[x].push_back(y);
		ver[y].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,greater<int>());
	for(int i=2;i<=n;i++) ans+=a[i];
	dfs(1,0);
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) cout<<res[i]<<' ';
}