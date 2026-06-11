#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (1LL << 55)
#define MOD (1000 * 1000 * 1000 + 7)
#define maxn 311

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int dp[maxn][maxn][maxn]; // dp[from][to][x changes left] - longest subsequence palindrome in range [from, to] with x changes left
char str[maxn];

int main(){
	int n, k;
	scanf("%s", str + 1);
	scanf("%d", &k);
	n = strlen(str + 1);

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++)
			dp[i][i][j] = 1;
	}

	for(int len = 2; len <= n; len++){
		for(int l = 1; l + len - 1 <= n; l++){
			int d = l + len - 1;

			for(int j = 0; j <= k; j++){
				if(j > 0)
					dp[l][d][j] = max(dp[l][d][j], dp[l][d][j - 1]);

				dp[l][d][j] = max(dp[l][d][j], dp[l + 1][d][j]);
				dp[l][d][j] = max(dp[l][d][j], dp[l][d - 1][j]);

				if(j > 0)
					dp[l][d][j] = max(dp[l][d][j], dp[l + 1][d - 1][j - 1] + 2);

				if(str[l] == str[d])
					dp[l][d][j] = max(dp[l][d][j], dp[l + 1][d - 1][j] + 2);
			}
		}
	}

	printf("%d\n", dp[1][n][k]);
	return 0;
}