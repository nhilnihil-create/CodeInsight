#include <bits/stdc++.h>
#define INF 1LL<<55
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll x[200005];
ll sum[200005];
ll X;


int main(void){
	scanf("%d%lld",&n,&X);
	for(int i=0;i<n;i++){
		scanf("%lld",&x[i]);
		sum[i+1]+=sum[i];
		sum[i+1]+=x[i];
	}
	ll ans=INF;
	for(int i=1;i<=n;i++){
		ll val=0;
		int rest=i*2;
		int j=n;
		ll c=5;
		while(j>0){
			int tgt=j-rest;
			if(tgt<0)tgt=0;
			val+=(sum[j]-sum[tgt])*c;
			if(val+(ll)i*X>=ans)break;
			rest=0;
			if(rest==0){
				rest=i;
				c+=2;
			}
			j=tgt;
		}
		ans=min(ans,val+(ll)i*X);
	}
	printf("%lld\n",ans+(ll)n*X);
	return 0;
} 