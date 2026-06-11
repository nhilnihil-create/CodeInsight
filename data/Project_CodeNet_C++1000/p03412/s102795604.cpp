#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,ans,a[N],b[N];
int calc(int v)
{
	int res=0;
	for(int l=1,r=n;l<=n;l++)
	{
		while(r&&a[l]+b[r]>=v)r--;
		res^=(n-r)&1;
	}
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=28;i>=0;i--)
	{
		for(int j=1;j<=n;j++)a[j]&=((1<<i+1)-1),b[j]&=((1<<i+1)-1);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		int x=calc(1<<i)^calc(2<<i)^calc(3<<i);
		ans|=x*(1<<i);
	}
	printf("%d\n",ans);
	return 0;
} 