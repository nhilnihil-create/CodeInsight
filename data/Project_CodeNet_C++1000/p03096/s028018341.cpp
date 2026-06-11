#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int MOD = 1000000007;

int n, c[MAXN], a[MAXN], dp[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);
		
	for(int i = n; i >= 0; i--){
		if(i == n)dp[i] = 1;
		else{
			if(i + 1 == n || c[i + 1] != c[i])a[c[i]] = (a[c[i]] + dp[i + 1]) % MOD;
			dp[i] = a[c[i]];
		}
	}
	printf("%d\n", dp[0]);
		
	return 0;
}
