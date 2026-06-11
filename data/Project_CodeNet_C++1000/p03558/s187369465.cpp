/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

int n,dist[100010];
deque <int> q;

int main()
{
	cin>>n;
	rep(i,100005) dist[i]=1e9;
	dist[1]=1;
	q.pb(1);
	while(!q.empty())
	{
		int t=q.front();
		q.pop_front();
		if(dist[(t+1)%n]>dist[t]+1)
		{
			dist[(t+1)%n]=dist[t]+1;
			q.pb((t+1)%n);
		}
		if(dist[t*10%n]>dist[t])
		{
			dist[t*10%n]=dist[t];
			q.push_front(t*10%n);
		}
	}
	cout<<dist[0]<<endl;
	return 0;
}