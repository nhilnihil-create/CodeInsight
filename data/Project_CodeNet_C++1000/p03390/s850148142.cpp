#include<bits/stdc++.h>
using namespace std;
long long n,a,b,l,r,ans,mid;
int check(long long x)
{
	int y=(a+x+1ll)/2ll;
	for(long long i=max(1ll,y-500ll);i<=min(x,y+500ll);i++)
	if(i*(a+x-i+1ll)>=a*b)return 0;
	return 1; 
}
int main()
{
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		if(a>b)swap(a,b);
		l=0;r=b+1ll;
		while(l+1ll<r)
		{
			mid=(l+r)/2ll;
			if(check(mid))l=mid;
			  else r=mid;
		}
		ans=a-1ll+l;
		cout<<ans<<endl;
	}
	return 0;
}