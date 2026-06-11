#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 7;
int n, ok[maxn][maxn], ans;

int main() {
	scanf("%d", &n);
	int m = n;
	if(n & 1) {
		--m;
		ans += m;
		for (int i = 1; i <= m; ++i) ok[i][n] = 1;
	}
	ans += m / 2 * (m - 2);
	for (int i = 1; i <= m; ++i) {
		for (int j = i + 1; j <= m; ++j) ok[i][j] = 1;
		ok[i][m - i + 1] = 0;
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; ++i) for(int j = i + 1; j <= n; ++j) 
		if(ok[i][j]) printf("%d %d\n", i, j);
	return 0;
}