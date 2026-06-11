#include <bits/stdc++.h>

using namespace std;

#define ll long long
ll input(){
	ll x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return f? -x:x;
}

const int N=107,M=1e5+7;
const ll mod=1e9+7;

ll dp[N][M],sum[M];
int a[N];

int main(){
	int n=input(),k=input();

	for(int i=0;i<n;i++) a[i]=input();
	for(int i=0;i<=n;i++) dp[i][0]=1;
	for(int i=1;i<=n;i++){
		sum[0]=0;
		for(int j=1;j<=k+1;j++) sum[j]=sum[j-1]+dp[i-1][j-1];
		for(int j=1;j<=k;j++) dp[i][j]=(sum[j+1]-sum[max(0,j-a[i-1])])%mod;
	}

	printf("%lld\n",dp[n][k]);
}
