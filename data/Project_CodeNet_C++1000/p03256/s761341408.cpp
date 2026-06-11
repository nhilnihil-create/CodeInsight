#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=200005;
int n,m;
char ss[N];
int X[N],Y[N];
int du[N][2];
vector<int> vec[N];
queue<int> q;
bool in[N];
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",ss+1);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);
		vec[y].push_back(x);
		du[y][ss[x]-'A']++;
		du[x][ss[y]-'A']++;
	}
	memset(in,true,sizeof(in));
	for (int u=1;u<=n;u++)
	{
		if (du[u][0]<=0||du[u][1]<=0)
		{
			in[u]=false;
			q.push(u);
		}
	}
	while (!q.empty())
	{
		int x=q.front();q.pop();
		int siz=vec[x].size();
		for (int u=0;u<siz;u++)
		{
			int y=vec[x][u];
			if (in[y]==false) continue;
			du[y][ss[x]-'A']--;
			if (du[y][ss[x]-'A']==0)	{in[y]=false;q.push(y);}
		}
	}
	for (int u=1;u<=n;u++) if (in[u])
	{
		printf("Yes\n");
		return 0;
	}
	printf("No\n");
	return 0;
}