#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back

typedef long long ll;

const ll MOD = 1e9+7;
const ll INF = 1e9+5;

int n;
int a[22][22];
int memo[22][3000005];

int dp(int i, int mask) {
	if (i == n) return 1;
	if (memo[i][mask] != -1) return memo[i][mask];
	int sol = 0;
	for (int j=0 ; j<n ; j++) {
		if ((1<<j)&mask) continue;
		if (a[i][j]) sol = (sol + dp(i+1, mask|(1<<j))) % MOD;
	}
	return memo[i][mask] = sol;
}

int main() {
	memset(memo, -1, sizeof memo);
	scanf("%d", &n);
	for (int i=0 ; i<n ; i++) {
		for (int j=0 ; j<n ; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	printf("%d\n", dp(0, 0));
	return 0;
}