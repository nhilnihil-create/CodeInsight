#include <bits/stdc++.h>
using namespace std;

int main(){
	char s[100001] = {};
	long dp[100001][4] = {};
	int mod = 1000000007;

	scanf("%s", s);
	int n = strlen(s);
	for(int i=n; i >= 0; i--) {
		for(int j=3; j >= 0; j--) {
			if(i == n) {
				dp[i][j] = (j == 3) ? 1 : 0;
			}else{
				int m = (s[i] == '?') ? 3 : 1;
				char str[4] = "ABC";
				dp[i][j] = m * dp[i+1][j];
				if(j < 3 && (m == 3 || s[i] == str[j]))
					dp[i][j] += dp[i+1][j+1];
				dp[i][j] %= mod;
			}
		}
	}
	printf("%ld\n", dp[0][0]);
}