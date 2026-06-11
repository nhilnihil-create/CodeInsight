/*Lucky_Glass*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=int(2e5);
int n;
ll X;
ll dst_sum[N+5];
int main(){
	scanf("%d%lld",&n,&X);
	for(int i=1,dst;i<=n;i++){
		scanf("%d",&dst);
		dst_sum[i]=dst_sum[i-1]+dst;
	}
	ll ans=ll(1e18);
	for(int k=1;k<=n;k++){ //决定丢多少次垃圾
		ll now=0,cof=1;
		for(int i=n;i>=1;i-=k){
			now+=(dst_sum[i]-dst_sum[max(i-k,0)])*max((cof+=2),5ll);
			if(now>ans) break; //最优性剪枝 
		}
		now+=(n+k)*X;
		ans=min(ans,now);
	}
	printf("%lld\n",ans);
	return 0;
}