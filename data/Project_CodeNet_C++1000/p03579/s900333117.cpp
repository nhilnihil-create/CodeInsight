#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const int N=100005;
vector<int> vec[N];
int n,m;
bool f[N][2];
bool in[N];
void bfs ()
{
	memset(f,false,sizeof(f));
	memset(in,false,sizeof(in));
	queue<int> q;
	q.push(1);f[1][0]=true;in[1]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		int siz=vec[x].size();in[x]=false;
		for (int i=0;i<siz;i++)
		{
			int y=vec[x][i];bool tf=false;
			if (f[x][0]&&!f[y][1])	{f[y][1]=true;tf=true;}
			if (f[x][1]&&!f[y][0])	{f[y][0]=true;tf=true;}
			if (tf) 
			{
				if (!in[y])	q.push(y);
				in[y]=true;
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int u=1;u<=m;u++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].push_back(y);vec[y].push_back(x);
	}
	bfs();
	int cnt=0,cnt1=0,cnt2=0;
	for (int u=1;u<=n;u++)
	{
		if (f[u][0]&&f[u][1]) cnt++;
		else if (f[u][1]) cnt1++;
		else cnt2++;
	}
	//printf("%d %d %d\n",cnt,cnt1,cnt2);
	LL ans=(LL)cnt1*cnt2+(LL)cnt*cnt2+(LL)cnt*cnt1+(LL)cnt*(cnt-1)/2;
	printf("%lld\n",ans-m);
	return 0;
}
