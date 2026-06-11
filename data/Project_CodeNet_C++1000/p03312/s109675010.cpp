#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
#define maxn 201000

LL a[maxn];
LL myabs(LL x){return (x<0)?-x:x;}
LL mymin(LL x,LL y){return (x<y)?x:y;}
LL mymax(LL x,LL y){return (x>y)?x:y;}
int main()
{
	int n,i,l,r;LL ans;
	scanf("%d",&n);a[0]=0;
	for (i=1;i<=n;i++) 
	{
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
	}
	l=1;r=3;ans=a[n];
	//1~l    l+1~i   i+1~r   r+1~n
	for (i=2;i<n-1;i++)
	{
		while (l+1<i && myabs(a[i]-a[l+1]-a[l+1])<myabs(a[i]-a[l]-a[l])) l++;
		while (r+1<n && myabs(a[n]-a[r+1]-(a[r+1]-a[i]))<myabs(a[n]-a[r]-(a[r]-a[i]))) r++;
		//p=a[l],q=a[i]-a[l],R=a[r]-a[i],s=a[n]-a[r]
		LL mx=mymax(mymax(a[l],a[i]-a[l]),mymax(a[r]-a[i],a[n]-a[r]));
		LL mn=mymin(mymin(a[l],a[i]-a[l]),mymin(a[r]-a[i],a[n]-a[r]));
		ans=mymin(ans,mx-mn);
	}
	printf("%lld\n",ans);
	return 0;
}
