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
			bool f=false;
			if(!((1<<i)&s))
			{
				for(int j=1;j<p[i];j++)
				{
					cnt++;
					poi+=i+1;
					if(poi>=G)
					{
						ans=min(ans,cnt);
						f=true;
						break;
					}
				}
			}
			if(poi>=G)break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

