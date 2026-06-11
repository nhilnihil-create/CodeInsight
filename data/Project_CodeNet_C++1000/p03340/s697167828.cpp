#include<bits/stdc++.h>
using namespace std;
long long a[200000+5],b[200000+5][22],c[22];
long long n,ans;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		long long t,j=0;
		t=a[i];
		while(t>0)
		{
			b[i][j]=t%2;
			j++;
			t/=2;
		}
	}
	long long l=1,r=1;
	if(n==1)
	{
		cout<<1;
		return 0;
	}
	for(int i=0;i<=21;i++)
	{
		c[i]+=b[1][i];
	}
	while(l<=n)
	{
		int flag=1,flag1;
		while(1)
		{
			r++;
			if(r>n)break;
			for(int i=0;i<=21;i++)
			{
				c[i]+=b[r][i];
				if(c[i]>1)flag=0;
			}
			if(flag==0||r==n)break;
		}
		if(flag==1)
		{
		//	cout<<'x'<<' '<<l<<' '<<r<<endl;
			ans+=(r-l+1)*(r-l+2)/2;
			break;
		}
		else 
		{
		//	cout<<'y'<<' '<<l<<' '<<r<<endl;
			ans+=(r-l)*(r-l+1)/2;
		}
			
		l++;
		while(l<=n)
		{
			flag1=1;
			for(int i=0;i<=21;i++)
			{
				c[i]-=b[l-1][i];
				if(c[i]>1)flag1=0;
			}
			if(flag1==0)
			{
				l++;
				
				continue;
			}
			else break;
		}
		if(r==n)
		{
		//	cout<<'z'<<' '<<l<<' '<<r<<endl;
			ans-=(r-l)*(r-l+1)/2;
			ans+=(r-l+1)*(r-l+2)/2;
			break;
		}
		else 
		{
			//cout<<'k'<<' '<<l<<' '<<r<<endl;
			ans-=(r-l)*(r-l+1)/2;
		}
		
		//cout<<'z'<<' '<<l<<' '<<r;
	}
	cout<<ans;
	return 0;
}