#include <bits/stdc++.h>

using namespace std;
const int inf = (int) 1e9;
const int maxn = (int)1e5 + 5;
int a[maxn];
int dp[maxn];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		dp[i] = inf;
	}
	dp[0] = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i + 1; j <= i + k; ++j){
			if(j < n){
				dp[j] = min(dp[j], dp[i] + abs(a[j] - a[i]));
			}
		}
	}
	printf("%d\n", dp[n - 1]);
	return 0;
}