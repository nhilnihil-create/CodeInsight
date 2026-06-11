// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;
#define int LL

const int inf = 1e9,maxn=3e5+5;
int n,c,a[maxn],b[maxn],mx1[maxn],mx2[maxn];
signed main(){
	scanf("%lld%lld",&n,&c);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&a[i],&b[i]);
//	for(int i=n+1;i<=2*n;i++)sum[i]=sum[i-1]+(b[i]-(a[i]-(i==n+1?0:a[i-1])));
//	for(int i=n-1;i>=1;i--)sumr[i]=sumr[i+1]+(b[i]-((i==n-1?c:a[i+1])-a[i]));
	int sum=0;for(int i=1;i<=n;i++)sum+=b[i],mx1[i]=max(mx1[i-1],sum-a[i]);
	sum=0;for(int i=n;i>=1;i--)sum+=b[i],mx2[i]=max(mx2[i+1],sum-(c-a[i]));
	int ans=max(mx1[n],mx2[1]);
	sum=0;
	for(int i=1;i<n;i++){
		sum+=b[i];
		ans=max(ans,sum-2*a[i]+mx2[i+1]); 
	}
//	printf("	%lld\n",mx2[2]);
	sum=0;
	for(int i=n;i>=2;i--){
		sum+=b[i];
		ans=max(ans,sum-2*(c-a[i])+mx1[i-1]);
//		printf("	%lld %lld\n",i,sum-a[i]+mx1[i+1]);
	}
	printf("%lld\n",ans);

	return 0;
}
