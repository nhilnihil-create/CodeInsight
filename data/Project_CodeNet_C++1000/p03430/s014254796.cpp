#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>

using namespace std;

int memo[301][301][301];
int visited[301][301][301];
char S[301];
int K, len;

int max(int i, int j) { if (i > j) { return i; } else { return j; } }
int dp(int i, int j, int k) {
	int M;
	if (visited[i][j][k] == 1) { return memo[i][j][k]; }

	if (i == j) {
		memo[i][j][k] = 0;
		visited[i][j][k] = 1;
	}
	else if (i + 1 == j) {
		memo[i][j][k] = 1;
		visited[i][j][k] = 1;
	}
	else {
		M = max(dp(i+1,j,k), dp(i,j-1,k));
		if (S[i] == S[j - 1]) { M = max(M, dp(i + 1,j - 1,k) + 2); }
		else if (k >= 1) { M = max(M, dp(i + 1,j - 1,k - 1) + 2); }
		memo[i][j][k] = M;
		visited[i][j][k] = 1;
	}
	return memo[i][j][k];
}

int main() {
	scanf("%s", S);
	scanf("%d", &K);
	len = strlen(S);

	for (int i = 0; i < 301; i++) {
		for (int j = 0; j < 301; j++) {
			for (int k = 0; k < 301; k++) {
				visited[i][j][k] = 0;
			}
		}
	}

	printf("%d\n", dp(0, len, K));
}