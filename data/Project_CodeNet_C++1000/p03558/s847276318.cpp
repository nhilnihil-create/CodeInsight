#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define INF63 1061109567
#define INF127 9187201950435737471
#define F first
#define S second
#define ll long long
#define N 100010
using namespace std;
int k;
int dist[N];
deque<int> dq;
int main(){
	int n,x,t;
	cin>>k;
	memset(dist,63,sizeof(dist));
	dq.push_front(1);
	dist[1]=1;
	while(!dq.empty())
	{
		x=dq.front();
		dq.pop_front();
		t=(x*10)%k;
		if(dist[t]>dist[x])
		{
			dist[t]=dist[x];
			dq.push_front(t);
		}
		t=(x+1)%k;
		if(dist[t]>dist[x]+1)
		{
			dist[t]=dist[x]+1;
			dq.push_back(t);
		}
	}
	cout<<dist[0]<<endl;
	return 0;
}