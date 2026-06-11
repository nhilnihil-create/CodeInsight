#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define enter putchar('\n')
#define space putchar(' ')
//#define ivorysi
#define MAXN 100005
typedef long long int64;
using namespace std;
template<class T>
void read(T &res) {
	res = 0;char c = getchar();T f = 1;
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') {
		res = res * 10 + c - '0';
		c = getchar();
	}
	res *= f;
}
template<class T>
void out(T x) {
	if(x < 0) {x = -x;putchar('-');}
	if(x >= 10) {
		out(x / 10);
	}
	putchar('0' + x % 10);
}
const int MOD = 1000000007;
int N,A[MAXN],fac[MAXN],invfac[MAXN],inv[MAXN],sum[MAXN],sum_of_sum[MAXN];
int inc(int a,int b) {
	return a + b >= MOD ? a + b - MOD : a + b;
}
int mul(int a,int b) {
	return 1LL * a * b % MOD;
}
void update(int &x,int y) {
	x = inc(x,y);
}
int C(int n,int m) {
	if(n < m) return 0;
	return mul(fac[n],mul(invfac[m],invfac[n - m]));
}
void Solve() {
    read(N);
	for(int i = 1 ; i <= N ; ++i) {
		read(A[i]);
		sum[i] = inc(sum[i - 1],A[i]);
		sum_of_sum[i] = inc(sum_of_sum[i - 1],sum[i]);
	}
	inv[1] = 1;
	for(int i = 2 ; i <= N ; ++i) {
		inv[i] = mul(inv[MOD % i],MOD - MOD / i);
	}
	fac[0] = invfac[0] = 1;
	for(int i = 1 ; i <= N ; ++i) {
		fac[i] = mul(fac[i - 1],i);
		invfac[i] = mul(invfac[i - 1],inv[i]);
	}
	int ans = 0;
	for(int i = 1 ; i <= N ; ++i) {
		if(i == N) update(ans,mul(sum[N],fac[N]));
		else {
			update(ans,mul(inc(sum[i],inc(sum[N],MOD - sum[N - i])),mul(mul(fac[i],C(N,i + 1)),fac[N - i - 1])));
			if(i < N - 1) {
				int t = inc(sum_of_sum[N - 1],MOD - sum_of_sum[i]);
				update(t,MOD - sum_of_sum[N - i - 1]);
				update(ans,mul(t,mul(mul(mul(2,fac[i]),C(N,i + 2)),fac[N - i - 2])));
			}
		}
	}
	out(ans);enter;
}
int main() {
#ifdef ivorysi
	freopen("f1.in","r",stdin);
#endif
	Solve();
	return 0;
}
