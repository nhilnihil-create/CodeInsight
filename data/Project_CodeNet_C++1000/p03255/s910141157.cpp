#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=2E5+10;
int n,x;
int a[N],opt[N];
long long sum[N],ans=100000000000000000ll;
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	long long s=0;
	for(int k=1;k<=n;k++){
		long long res=1ll*(n+k)*x+s,d=1;
		for(int i=n;i>0;i-=k){
			int j=max(0,i-k);
			long long x=d*d*k,q=2*d+1;d++;
			res+=(sum[i]-sum[j])*max(q,5ll);
			if(res>ans) break;
		}
		ans=min(res,ans);
	}
	printf("%lld\n",ans);
	return 0;
}