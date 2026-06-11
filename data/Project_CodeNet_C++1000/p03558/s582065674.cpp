#include <iostream>
#include <queue>
using namespace std;

int k,dist[100010];
bool used[100010];
deque<int> q;

inline void add_front(int x,int d)
{
	if(d<dist[x])
	{
		dist[x]=d;
		q.push_front(x);
	}
}

inline void add_back(int x,int d)
{
	if(d<dist[x])
	{
		dist[x]=d;
		q.push_back(x);
	}
}

int main()
{
	cin>>k;
	fill(dist,dist+100000,(1e9+7));
	
	add_front(1,0);
	while(!q.empty())
	{
		int x=q[0];q.pop_front();
		
		if(used[x]) continue;
		used[x]=1;
		
		int d=dist[x],cx=x*10%k;
		add_front(cx,d);
		
		cx=(x+1)%k;
		add_back(cx,d+1);
	}
	
	cout<<dist[0]+1;
	
	return 0;
}