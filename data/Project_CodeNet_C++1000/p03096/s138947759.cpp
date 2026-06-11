#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

int n, a, M=1e9+7, dp[N]={1}, pr[N];
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		scanf("%d", &a);
		dp[i] = dp[i-1];
		if(pr[a]>0 && i-pr[a]>1) dp[i] = (dp[i] + dp[pr[a]]) % M;
		pr[a] = i;
	}
	cout << dp[n];
	return 0;
}