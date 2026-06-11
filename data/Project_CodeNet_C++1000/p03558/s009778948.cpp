#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
const int N=1e6;
bool vis[N];
deque <pair<int,int> > q;
int k;
void bfs()
{
	while(!q.empty())
	{
		pair <int,int> t=q.front();
		q.pop_front();
		if(vis[t.first]) continue;
		vis[t.first]=true;
		if(!t.first)
		{
			printf("%d\n",t.second);
			exit(0);
		}
		q.push_front(make_pair(t.first*10%k,t.second));
		q.push_back(make_pair((t.first+1)%k,t.second+1));
	}
}
int main()
{
	scanf("%d",&k);
	q.push_front(make_pair(1,1));
	bfs();
	return 0;
}
