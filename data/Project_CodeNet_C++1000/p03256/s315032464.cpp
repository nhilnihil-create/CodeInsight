#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<queue>
using namespace std;
const int N=200100;
int n,m,val[N],vis[N];
vector<int> E[N];
char s[N];
queue<int> Q;
int check(int i)
{
	int v1=0,v2=0;			
	for(auto x:E[i])
	{
		if(vis[x]) continue;
		if(val[x]==0) v1=1;
		else v2=1;
	}
	return v1*v2;
}
int main()
{
	cin>>n;cin>>m;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) val[i]=s[i]-'A';
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		E[x].push_back(y);
		if(x^y) E[y].push_back(x);	
	}
	for(int i=1;i<=n;i++) 
		if(!check(i)) Q.push(i),vis[i]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		for(auto p:E[x]) 
			if(!vis[p]&&!check(p))
				Q.push(p),vis[p]=1; 
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]) {puts("Yes");return 0;}
	puts("No");
}