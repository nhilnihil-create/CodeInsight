#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

const int mod = 1000000007;

int n, c[200005];
int dp[200005], sum_dp_col[200005];

int main(){
	scanf("%d", &n);
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &c[i]);
		dp[i] = dp[i - 1];
		if(i == 1 || (c[i] != c[i - 1])){
			dp[i] += sum_dp_col[c[i]];
			dp[i] %= mod;
			sum_dp_col[c[i]] = dp[i];
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}