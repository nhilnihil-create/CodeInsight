
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
#include<iostream>
#include<cstring>
#define ll long long
#define maxn 100005
			 
#define p 1000000007
#define re(i,a,b) for(int i=a;i<=b;i++)
#define for_edge(x) for(int i=head[x];i;i=e[i].nxt)
using namespace std;
inline int read(){char c=getchar();int f=1;int ans = 0;while(c>'9'||c<'0'){if(c=='-')f=-f;c=getchar();}while(c<='9'&&c>='0'){ans =ans*10+c-'0';c=getchar();}return ans*f;}
//_____________________________________________________________________________________________________
deque<int>q;
int vis[maxn],dis[maxn];
int main()
{
	int k = read();
	memset(dis,0x3f,sizeof(dis));
	dis[1] = 1;
	q.push_back(1);
	while(!q.empty() )
	{
		int x = q.front() ; 
		q.pop_front() ;
		if(vis[x])
			continue;
		vis[x] = 1;
		if(dis[x*10%k]>dis[x])
		{
			dis[x*10%k] = dis[x];
			q.push_front(x*10%k);
		}
		if( dis[(x+1)%k]>dis[x] + 1 )
		{
			dis[(x+1)%k] = dis[x] + 1;
			q.push_back((x+1)%k);
		}
	}
	printf("%d\n",dis[0]);
    return 0;
}

