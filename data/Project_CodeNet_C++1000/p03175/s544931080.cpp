#include <stdio.h>
#include <vector>
using namespace std;
#define PB push_back
typedef long long int ll;
constexpr int kN = int(1E5 + 10), kMod = int(1E9 + 7);
vector<int> graph[kN];
ll dp[kN][2];
void dfs(int pos, int from = 1) {
	for (int i : graph[pos]) if (i != from) dfs(i, pos);
	dp[pos][0] = dp[pos][1] = 1;
	for (int i : graph[pos]) if (i != from) {
		dp[pos][0] = dp[pos][0] * (dp[i][0] + dp[i][1]) % kMod;
		dp[pos][1] = dp[pos][1] * dp[i][0] % kMod;
	}
	return ;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 2, l, r; i <= n; i++) {
		scanf("%d%d", &l, &r);
		graph[l].PB(r);
		graph[r].PB(l);
	}
	dfs(1);
	printf("%lld\n", (dp[1][0] + dp[1][1]) % kMod);
}
