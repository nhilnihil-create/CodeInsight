#include<bits/stdc++.h>
using namespace std;
long long n,a[202020],sum[202020],ans=1e18+10;
long long ch(int x,int y)
{
	return sum[y]-sum[x-1];
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+a[i-1];
	}
	int a=1,c=3;
	for(int b=2;b<=n-2;b++)
	{
		while(a<b-1 && abs(ch(1,a)-ch(a+1,b))>abs(ch(1,a+1)-ch(a+2,b)))
		{
			a++;
		}
		while(c<n-1 && abs(ch(b+1,c)-ch(c+1,n))>abs(ch(b+1,c+1)-ch(c+2,n)))
		{
			c++;
		}
		long long cha[4];
		cha[0]=ch(1,a);
		cha[1]=ch(a+1,b);
		cha[2]=ch(b+1,c);
		cha[3]=ch(c+1,n);
		sort(cha,cha+4);
		ans=min(ans,cha[3]-cha[0]);
	}
	cout<<ans<<endl;
	return 0;
}