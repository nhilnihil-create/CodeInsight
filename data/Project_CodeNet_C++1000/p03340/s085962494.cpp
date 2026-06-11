#include<bits/stdc++.h>

using namespace std;

const int N=200000+5;

int n;
int dis[N];
long long front1[N];
long long front2[N];
int s=1;
int t=1;
long long ans;

int main()
{
	cin>>n;
	front2[0]=0;
	front1[0]=0;
	for(int i=1;i<=n;++i)
	{
		cin>>dis[i];
		front1[i]=front1[i-1]^dis[i];
		front2[i]=front2[i-1]+dis[i];
	}
	for(;;)
	{
		while(t<=n&&(front1[t]^front1[s-1])==(front2[t]-front2[s-1]))
		{
			t++;
		}
		ans+=t-s;
		s++;
		if(s>n)break;
	}
	cout<<ans;
	return 0;
}