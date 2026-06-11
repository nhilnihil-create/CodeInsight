#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],sum[N];
inline long long s(int l,int r)
{
	return sum[r]-sum[l-1];
} 
int main()
{
	int n,l=1,r=3;
	long long ans=LLONG_MAX;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	for(int i=2;i<=n-2;i++)
	{
		while(l+1<i&&abs(s(1,l)-s(l+1,i))>=abs(s(1,l+1)-s(l+2,i)))
			l++;
		while(r+1<n&&abs(s(i+1,r)-s(r+1,n))>=abs(s(i+1,r+1)-s(r+2,n)))
			r++;
		long long b=s(1,l),c=s(l+1,i),d=s(i+1,r),e=s(r+1,n);
		ans=min(ans,max(max(b,c),max(d,e))-min(min(b,c),min(d,e)));
	}
	printf("%lld\n",ans);
	return 0;
}
