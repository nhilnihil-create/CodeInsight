/* - - - - - - - - - - - - - - -
	User : 		VanishD
	problem :
	Points : 	
- - - - - - - - - - - - - - - */
# include <bits/stdc++.h>
# define 	ll 		long long
using namespace std;
const int inf = 0x3f3f3f3f, INF = 0x7fffffff;
const ll  infll = 0x3f3f3f3f3f3f3f3fll, INFll = 0x7fffffffffffffffll;
int read(){
	int tmp = 0, fh = 1; char ch = getchar();
	while (ch < '0' || ch > '9'){ if (ch == '-') fh = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9'){ tmp = tmp * 10 + ch - '0'; ch = getchar(); }
	return tmp * fh;
}
const int N = 21;
int n, f[N][N], numl[N], numr[N];
char s[N * 2];
ll ans;
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read();
	scanf("\n%s", s + 1);
	int lim = (1 << n);
	for (int i = 0; i < lim; i++){
		int l = 0, r = 0;
		for (int j = 1; j <= n; j++)
			if ((i & (1 << (j - 1))) == 0)
				numl[++l] = s[j]; 
				else numr[++r] = s[j];
		for (int j = 1, k = l; j < k; j++, k--) swap(numl[j], numl[k]);
		for (int j = 1, k = r; j < k; j++, k--) swap(numr[j], numr[k]);
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for (int j = 0; j <= r; j++)
			for (int k = 0; k <= l; k++){
				int tmp = j + k + 1;
				if (j < r && s[n + tmp] == numr[j + 1]) f[j + 1][k] += f[j][k];
				if (k < l && s[n + tmp] == numl[k + 1]) f[j][k + 1] += f[j][k];
			}
		ans = ans + f[r][l];
	}
	printf("%lld\n", ans);
	return 0;
}
