#include<iostream>
using namespace std;
#define ll long long
const ll mod=1e9+7;
ll n,k,a[107],dp[107][100007],pre[100007];

int main(){
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=0;i<=n;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k+1;j++){
			pre[j]=pre[j-1]+dp[i-1][j-1];
		}
		for(int j=1;j<=k;j++){
			dp[i][j]=(dp[i][j]+pre[j+1]-pre[max((ll)0,j-a[i])])%mod;
		}
	}
	printf("%lld",dp[n][k]);
}
