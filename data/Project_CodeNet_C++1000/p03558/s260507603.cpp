#include<cstdio>
#include<queue>
#define P std::pair<int,int>
#define F first
#define S second
std::deque<P> q;
int n;
bool used[100010];
signed main()
{
	scanf("%d",&n),q.push_back(P(1,1));
	while(!q.empty())
	{
		P u(q.front());q.pop_front();
		if(!used[u.F])
		{
			used[u.F]=1;
			if(!u.F)
				return printf("%d\n",u.S),0;
			q.push_front(P(u.F*10%n,u.S)),q.push_back(P((u.F+1)%n,u.S+1));
		}
	}
}