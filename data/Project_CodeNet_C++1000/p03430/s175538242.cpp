#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
template<typename T> void chkmax(T &a, const T &b) { a = a > b ? a : b; }
template<typename T> void chkmin(T &a, const T &b) { a = a < b ? a : b; }

const int MAXN = 305;
char S[MAXN];
int f[2][MAXN][MAXN], n, K;

int main() {
	scanf("%s%d", S + 1, &K);
	n = strlen(S + 1);
	memset(f[1], 0xc0, sizeof(f[1]));
	for (int i = 0; i <= K; i++) {
		int a = i & 1, b = !a;
		for (int j = n; j > 0; j--) {
			f[a][j][j] = 1;
			for (int k = j + 1; k <= n; k++) {
				chkmax(f[a][j][k], max(f[a][j + 1][k], f[a][j][k - 1]));
				chkmax(f[a][j][k], max(f[b][j][k], f[S[j] == S[k] ? a : b][j + 1][k - 1] + 2));
			}
		}
	}
	printf("%d\n", f[K & 1][1][n]);
	return 0;
}