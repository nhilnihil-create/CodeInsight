#include"bits/stdc++.h"
using namespace std;

#define MAX 5002

int n;
int A;
int B;

long long int dp[MAX][MAX];
bool us[MAX][MAX];


vector<int> v;


inline long long int dfs(int a, int b) {
	if (a == n) {
		return 0;
	}
	if (us[a][b])return dp[a][b];
	us[a][b] = true;
	dp[a][b] = LLONG_MAX;
	if (b == 0 || v[b - 1] < v[a]) {
		dp[a][b] = min(dp[a][b], dfs(a + 1, a + 1));
	}
	if (b == 0 || v[b - 1] < v[a]) {
		dp[a][b] = min(dp[a][b], dfs(a + 1, b) + A);
	}
	else {
		dp[a][b] = min(dp[a][b], dfs(a + 1, b) + B);
	}
	return dp[a][b];
}

int main() {
	cin >> n >> A >> B;
	for (int i = 0; i < n; i++) {
		int p;
		scanf("%d", &p);
		v.push_back(p);
	}
	printf("%lld\n", dfs(0, 0));
	return 0;
}
