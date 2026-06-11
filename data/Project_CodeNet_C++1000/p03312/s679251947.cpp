#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,a[maxn];
ll sum[maxn];
int l1,l2;
//[1,l1][l1+1,i][i+1,l2][l2+1,r]
//枚举中间分界点i 把区间划成左右两半
ll mx,mn;
ll ans;
ll getsum(int l,int r)
{
	return sum[r]-sum[l-1];
}
ll update(int l,int r)
{
	mx=max(mx,getsum(l,r));
	mn=min(mn,getsum(l,r));
}
int main()
{ 
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
	{
	 scanf("%d",&a[i]);
     sum[i]=sum[i-1]+a[i];
    }
    ans=1e18,l1=1,l2=3;//考虑n==4的情况下是这些值
	//l1和l2最靠左是这些值，以后是单增的 
	for(int i=2;i<=n-2;++i)
	{
		mx=-1e18,mn=1e18;
		while(l1+2<=i&&abs(getsum(1,l1)-getsum(l1+1,i))>abs(getsum(1,l1+1)-getsum(l1+2,i)))l1++;
		while(l2+2<=n&&abs(getsum(i+1,l2)-getsum(l2+1,n))>abs(getsum(i+1,l2+1)-getsum(l2+2,n)))l2++;
		update(1,l1),update(l1+1,i);
		update(i+1,l2),update(l2+1,n);
		ans=min(ans,mx-mn);
	} 
	printf("%lld\n",ans);
	return 0;
}