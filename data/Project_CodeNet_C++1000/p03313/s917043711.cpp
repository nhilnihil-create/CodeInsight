#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second

const ll INF=10000000000;

int main(){
	static ll n;
	static ll a[1<<18];
	scanf("%lld",&n);
	for(int i=0;i<(1<<n);i++){
		scanf("%lld",&a[i]);
	}
	
	static ll dp[1<<18][2];
	for(int i=0;i<(1<<n);i++){
		dp[i][0]=a[i];
		dp[i][1]=-INF;
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<(1<<n);i++){
			if((i>>j)&1){
				dp[i][1]=max(dp[i][1],dp[i-(1<<j)][0]);
				if(dp[i][0]<dp[i][1])swap(dp[i][0],dp[i][1]);
				dp[i][1]=max(dp[i][1],dp[i-(1<<j)][1]);
			}
		}
	}
	ll ret=0;
	for(int i=1;i<(1<<n);i++){
		ret=max(ret,dp[i][0]+dp[i][1]);
		printf("%lld\n",ret);
	}
}

