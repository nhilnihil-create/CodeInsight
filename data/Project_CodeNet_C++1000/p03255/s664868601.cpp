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
const int N = 201000;
int n;
ll x, p[N], ans = infll, sum[N];
int main(){
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(), x = read();
	for (int i = 1; i <= n; i++) p[i] = read();
	int lim = n / 1000;
	sum[0] = n * x;
	for (int i = 1; i <= n; i++) sum[i] = x; 
	sum[1] += p[n] * 5; 
	for (int i = 1; i <= n; i++){
		int id = n - i + 1, nxt = 1, k = i - 1;
		bool flag = false;
		for (int j = 1; j <= k; j = nxt + 1){
			nxt = k / (k / j);
			int w = k / j + 1;
			if (j != 1 && flag == true){
				int las = k / (j - 1) + 1;
				sum[j] = sum[j] - p[id] * (2 * las + 1);
			}
			if (j >= lim || k / j == 1){
				sum[j] = sum[j] + p[id] * (2 * w + 1);
				flag = true;
			}
		} 
	} 
	for (int i = 1; i <= n; i++){
		sum[i] += sum[i - 1]; 
		if (i >= lim) ans = min(ans, sum[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
