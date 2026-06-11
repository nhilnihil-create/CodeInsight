#include<cstdio>
using namespace std;
int n,l,r;
long long ai[200005],sum[200005],xsum[200005],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&ai[i]);
		sum[i]=sum[i-1]+ai[i];
		xsum[i]=xsum[i-1]^ai[i];
	}
	r=1;
	for(l=1;l<=n;l++){
		while(r<=n&&(sum[r]-sum[l-1])==(xsum[r]^xsum[l-1])){
			r++;
		}
		r--;
		ans += (r-l+1);
	}
	printf("%lld\n",ans);
}