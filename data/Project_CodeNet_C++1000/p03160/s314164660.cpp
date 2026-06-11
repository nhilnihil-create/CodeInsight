#include <bits/stdc++.h>

using namespace std;

const int maxn = (int)1e5 + 5;
int a[maxn];
int dp[maxn];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
	}
	dp[0] = 0;
	for(int i = 1; i < n; ++i){
		if(i >= 2)
			dp[i] = min(dp[i - 1] + abs(a[i] - a[i - 1]), dp[i - 2] + abs(a[i] - a[i - 2]));
		else
			dp[i] = abs(a[i] - a[i - 1]);
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}