#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;
#define  LL long long

const int maxn = 1e5+55;

LL a[maxn],b[maxn];
LL x[maxn],v[maxn];
LL sum[maxn];
int main()
{
	LL n,c;
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>x[i]>>v[i];

	for(LL i=1;i<=n;i++)
		a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
	x[n+1]=c;

	for(LL i=n;i>=1;i--)
		b[i]=b[i+1]+v[i]-(x[i+1]-x[i]);
	a[0]=b[n+1]=-1231231222231323;

	for(LL i=1;i<=n;i++)
		a[i]=max(a[i-1],a[i]);

	for(LL i=n;i>=1;i--)
		b[i]=max(b[i],b[i+1]);
	a[0]=a[n+1]=0;
	LL ans=0;
	for(LL i=1;i<=n;i++){
		ans=max(ans,-x[i]+a[i]+b[i+1]); //顺时针，再折回
		ans=max(ans,a[i]);//顺时针，不折回
		ans=max(ans,b[i]);//逆时针，不折回
		ans=max(ans,-(c-x[i])+b[i]+a[i-1]);//逆时针 再折回
	}
	cout<<ans<<endl;




}
