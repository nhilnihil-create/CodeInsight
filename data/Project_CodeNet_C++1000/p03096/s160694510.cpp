#include<cstdio>
#include<vector>
#define ll long long
#define rep(i, l, r) for(int i=l; i<=r; ++i)
#define N 200005
#define mod 1000000007
using namespace std;
int t;
int n;
int a[N];
int dp[N];
int f[N];
int main() {
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	dp[0]=1;
	rep(i, 1, n){
		dp[i]=0;
		if(i==1 || a[i-1]!=a[i]) f[a[i]]=(f[a[i]]+dp[i-1])%mod;
		dp[i]=(dp[i]+f[a[i]])%mod;
	}
	printf("%d", dp[n]);
	return 0;
}