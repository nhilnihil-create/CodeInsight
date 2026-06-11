#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)

using namespace std;

const int N = 310;
int n, m, K, ans;
char s[N], t[N];
int f[N][N][N];

int main() {
	int i, j, k;
	scanf("%s", s+1); n = strlen(s+1);
	m = n >> 1;
	rep(i, 1, n) t[i] = s[n-i+1];
	
	scanf("%d", &K);
	ans = 1;
	rep(i, 1, n-1) {
		rep(j, 1, n-i) 
			rep(k, 0, K) {
				f[i][j][k] = max(f[i-1][j][k], f[i][j-1][k]);
				if(k) f[i][j][k] = max(f[i][j][k], f[i][j][k-1]);
				if(s[i] == t[j]) {
					f[i][j][k] = max(f[i-1][j-1][k]+1, f[i][j][k]);
				} else {
					if(k) f[i][j][k] = max(f[i-1][j-1][k-1]+1, f[i][j][k]);
				}
				//printf("%d %d %d %d\n", i, j, k, f[i][j][k]);
			}
		ans = max(ans, f[i][n-i-1][K]*2+1);
		ans = max(ans, f[i][n-i][K]*2);
	}
	printf("%d\n", ans);
	return 0;
}