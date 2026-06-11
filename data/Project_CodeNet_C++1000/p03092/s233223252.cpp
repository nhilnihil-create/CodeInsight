/*
Problem Source : agc-032D
Author : oier_hzy
Time : Nov 24 2019
*/

/*
A : move a element to the right
B : ... left

In the best case, there're several fixed elements
We could consider all the circumstances during DP procession

f[i][j] : the first i elements (by coordinate) has been considered, and the last fixed coordinate is j
*/

#include <cstdio>
typedef long long ll;

template <typename _tp> inline void cmin(_tp&x, const _tp y) {if(x > y) x = y;}

const ll oo = 0x3f3f3f3f3f3f3f3f;
const int N = 5001;
int a[N];
ll f[N], g[N];
int n, A, B;

int main() {
	scanf("%d%d%d", &n, &A, &B);
	for(int i = 1; i <= n; ++ i) scanf("%d", a+i);
	
	for(int i = 0; i <= n; ++ i) f[i] = g[i] = +oo;
	f[0] = 0;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < a[i]; ++ j) {
			cmin(g[j], f[j] + A);
			cmin(g[a[i]], f[j]);
		}
		for(int j = a[i]; j <= n; ++ j)
			cmin(g[j], f[j] + B);
		for(int j = 0; j <= n; ++ j) f[j] = g[j], g[j] = +oo;
	}
	
	ll Ans = +oo;
	for(int i = 0; i <= n; ++ i)
		cmin(Ans, f[i]);
	printf("%lld\n", Ans);
	return 0;
}