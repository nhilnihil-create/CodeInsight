#include <bits/stdc++.h>

using namespace std;

#define N 200000
#define INF 0x3f3f3f3f

char str[N + 2];
int sum[26][N + 2];
int dp[N + 2];
map<int, int> m[2];
int n;

int convert(int p){
	int ans, i;

	for (i = 0, ans = 0; i < 26; i++){
		if (sum[i][p] % 2){
			ans |= (1 << i);
		}
	}

	return ans;
}

int main(){
	int i, j, x;

	scanf("%[^\r\n]%n", str + 1, &n);

	// Cumulative sum of each character
	for (i = 'a'; i <= 'z'; i++){
		for (j = 1; j <= n; j++){
			sum[i - 'a'][j] = sum[i - 'a'][j - 1] + ((int)str[j] == i);
		}
	}

	m[0][convert(0)] = 0;
	dp[0] = 0;

	for (i = 1; i <= n; i++){
		x = convert(i);
		dp[i] = INF;

		// If same index parity has an entry with the same parity
		if (m[i % 2].count(x)){
			dp[i] = min(dp[i], m[i % 2][x] + 1);
		}

		// If the other index parity has an entry with the same parity except for one character
		for (j = 0; j < 26; j++){
			x ^= (1 << j);

			if (m[(i + 1) % 2].count(x)){
				dp[i] = min(dp[i], m[(i + 1) % 2][x] + 1);
			}

			x ^= (1 << j);
		}

		if (m[i % 2].count(x)){
			m[i % 2][x] = min(m[i % 2][x], dp[i]);
		}
		else{
			m[i % 2][x] = dp[i];
		}
	}

	printf("%d\n", dp[n]);

	return 0;
}