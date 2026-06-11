#include<bits/stdc++.h>
using namespace std;
int n;
long long sum[202020],ans=1e18+10;
void get(int l,int r,long long &f,long long &s)
{
	long long res=1e18+10;
	int ll=1,rr=r-1;
	while(ll<=rr)
	{
		int mid=ll+rr>>1;
		long long a=sum[mid]-sum[l-1],b=sum[r]-sum[mid];
		if(abs(a-b)<res)
		{
			res=abs(a-b);
			f=a;
			s=b;
		}
		if(a<=b)
		{
			ll=mid+1;
		}
		else
		{
			rr=mid-1;
		}
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		sum[i]=a+sum[i-1];
	}
	for(int i=2;i<=n-2;i++)
	{
		long long a,b,c,d,can;
		get(1,i,a,b);
		get(i+1,n,c,d);
		can=max(max(a,b),max(c,d))-min(min(a,b),min(c,d));
		ans=min(ans,can);
	}
	cout<<ans<<endl;
	return 0;
}