#include<bits/stdc++.h>
using namespace std;
long long a,k,x[100005],ans=999999999999999;
int main()
{
	cin>>a>>k;
	for(int i=1;i<=a;i++)
	{
		cin>>x[i];
		if(i>=k)
		{
			if(x[i]<=0&&x[i-k+1]<=0)
				ans=min(ans,-x[i-k+1]);
			else if(x[i]>0&&x[i-k+1]<=0)
			{
				if(x[i]>(-x[i-k+1]))
				{
					ans=min(ans,x[i]-x[i-k+1]*2);
				}
				else 
				{
					ans=min(ans,x[i]*2-x[i-k+1]);
				}
			}	
			else if(x[i]>=0&&x[i-k+1]>=0)
				ans=min(ans,x[i]);
		}
	}
	cout<<ans<<endl;
}