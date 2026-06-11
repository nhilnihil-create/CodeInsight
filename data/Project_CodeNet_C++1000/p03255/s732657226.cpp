// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

const int inf = 1 << 30;
const int maxn=2e5+5;

ULL n,x;
ULL a[maxn],sum[maxn];

int main(){
	scanf("%llu%llu",&n,&x);
	for(int i=1;i<=n;i++)scanf("%llu",&a[i]),sum[i]=sum[i-1]+a[i];
	ULL ans=1ll<<60;
	for(LL k=1;k<=n;k++){
		ULL res=0,base=5;
		for(LL i=n;i>=1;i-=k){
			ULL tmp;
			if(i-k<=0)tmp=sum[i]-sum[0];
			else tmp=sum[i]-sum[i-k];
//			printf("%llu \n",tmp);
			if(i==n){
				res+=tmp*base;
			}else res+=tmp*base,base+=2;
			if(res+(n+k)*x>ans)break;
		}
		ans=min(ans,res+(n+k)*x);
	}
	printf("%llu\n",ans);

	return 0;
}
