#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int dis[N],n;
deque<int>q;
int main()
{
	scanf("%d",&n);
	memset(dis,0x3f,sizeof(dis));
	dis[1]=1;
	q.push_back(1);
	while(1)
	{
		int k=q.front(),x=k*10%n,y=(k+1)%n;
		q.pop_front();
		if(k==0)
			break;
		if(dis[x]>dis[k])
		{
			dis[x]=dis[k];
			q.push_front(x);
		}
		if(dis[y]>dis[k]+1)
		{
			dis[y]=dis[k]+1;
			q.push_back(y);
		}
	}
	printf("%d\n",dis[0]);
	return 0;
}