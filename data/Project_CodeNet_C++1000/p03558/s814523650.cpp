#include<bits/stdc++.h>
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
using namespace std;
const int N=1e5+5;
int n;
bool visit[N];
deque<pii>q;
void bfs()
{
	q.push_back(mp(1,1));
	while(true)
	{
		pii p=q.front();q.pop_front();
		if(visit[p.F])continue;
		visit[p.F]=true;
		if(p.F==0)
		{
			cout<<p.S<<endl;
			return;
		}
		q.push_front(mp(p.F*10%n,p.S));
		q.push_back(mp((p.F+1)%n,p.S+1));
	}
}
signed main()
{
	cin>>n;
	bfs();
	return 0;
}