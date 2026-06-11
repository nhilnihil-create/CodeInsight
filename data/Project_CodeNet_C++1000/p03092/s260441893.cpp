#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 5010;
typedef long long ll;

int n, A, B, p[maxn], rp[maxn];
ll f[maxn][maxn];
int sum[maxn], K[maxn][maxn], C[maxn][maxn];

int main() {
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		rp[p[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j >= 1; j--) {
			K[i][j] = K[i][j+1];
			if (rp[j] >= i) K[i][j] = rp[j];
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			if (p[i] >= j) sum[i] = sum[i-1] + 1;
			else sum[i] = sum[i-1];
		}
		for (int i = 1; i <= n; i++) {
			int k = K[i][j];
			if (k) {
				C[i][j] = sum[k]-sum[i-1];
			}
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = n; j >= 1; j--) {
			if (!K[i][j]) f[i][j] = 0;
			else {
				ll c = C[i][j], k = K[i][j];
				f[i][j] = min(1ll*A*(c-1)+f[k+1][p[k]+1], B+f[i][p[k]+1]);
			}
		}
	}
	printf("%lld\n", f[1][1]);
	return 0;
}