#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;
#define int long long
int n, m, a[maxn][3], c[maxn], ans;
signed main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; ++i) for(int j = 0; j < 3; ++j) scanf("%lld", &a[i][j]);
	for(int k = 0; k < 8; ++k){
		for(int i = 1; i <= n; ++i){
			c[i] = 0;
			for(int j = 0; j < 3; ++j){
				int x = a[i][j];
				if(k & (1 << j)) x = x * -1;
				c[i] += x; 
			}
		}
		sort(c + 1, c + n + 1);
		int cnt = 0;
		for(int i = n; i > n - m; --i) cnt += c[i];
		ans = max(ans, cnt);
	}
	printf("%lld", ans);
	return 0;
}