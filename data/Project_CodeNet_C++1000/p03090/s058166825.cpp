#include <cstdio>
const int N = 105;
int n, ans;
int vis[N][N];
int main() {
	scanf("%d", &n);
	ans = n * (n - 1) / 2;
	if (n % 2 == 0) {
		for (int i = 1; i <= n; i++)
		if (!vis[i][n - i + 1])
			vis[i][n - i + 1] = vis[n - i + 1][i] = true, ans--;
	} else {
		for (int i = 1; i < n; i++)
		if (!vis[i][n - i]) vis[i][n - i] = vis[n - i][i] = true, ans--;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		if (!vis[i][j]) printf("%d %d\n", i, j);
	return 0;
}