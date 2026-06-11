#include<bits/stdc++.h>
using namespace std;
int main()
{
	int D,G,p[11],c[11];
	cin>>D>>G;G/=100;
	int ans=G;
	for(int i=0;i<D;i++)cin>>p[i]>>c[i],c[i]/=100;
	for(int s=0;s<(1<<D);s++)
	{
		int cnt=0,poi=0;
		for(int i=0;i<D;i++)
		{
			if((1<<i)&s)
			{
				cnt+=p[i];
				poi+=(i+1)*p[i]+c[i];
			}
		}
		if(poi>=G)
		{
			ans=min(ans,cnt);
			continue;
		}
		for(int i=D-1;i>=0;i--)
		{
			if(!((1<<i)&s))
			{
				if(poi+(i+1)*(p[i]-1)>=G)
				{
					ans=min(ans,cnt+(G-poi)/(i+1)+((G-poi)%(i+1)>0));
					break;
				}
				else
				{
					cnt+=p[i]-1;
					poi+=(i+1)*(p[i]-1);
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}