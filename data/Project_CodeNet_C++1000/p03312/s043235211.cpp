#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r=3,a,b,c,d,Min,s[200010],x,y;
int main()
{
	cin>>n;
	Min=2e9;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		s[i]=s[i-1]+x;
	}
	for(int i=2;i<n;i++)
	{
		while(l<i&&abs(s[i]-s[l+1]*2)<=abs(s[i]-s[l]*2))l++;
		while(r<n&&abs(s[n]-s[r+1]*2+s[i])<=abs(s[n]-s[r]*2+s[i]))r++;
		a=s[l];
		b=s[i]-s[l];
		c=s[r]-s[i];
		d=s[n]-s[r];
		x=min(min(a,b),min(c,d));
		y=max(max(a,b),max(c,d));
		Min=min(Min,y-x);
	}
	cout<<Min;
	return 0;
}