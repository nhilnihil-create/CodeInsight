#include<bits/stdc++.h>
using namespace std;
const int m=100000009;
int k,dist[100000];
deque<int> q;
int main()
{
	cin.tie(0);
	cin>>k;
	for (int i=0;i<k;i++)
	{
		dist[i]=m;
	}
	dist[1]=1;
	q.push_back(1);
	while(q.size())
	{
		int f=q.front();
		q.pop_front();
		if (dist[(10*f)%k]>dist[f])
		{
			dist[(10*f)%k]=dist[f];
			q.push_front((10*f)%k);	
		}
		if (dist[(f+1)%k]>dist[f]+1)
		{
			dist[(f+1)%k]=dist[f]+1;
			q.push_back((f+1)%k);	
		}
	}
	cout<<dist[0];
	return 0;
}