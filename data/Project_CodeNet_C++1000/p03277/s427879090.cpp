#include <bits/stdc++.h>
#define MAX_N 100000
#define mid ((l+r)>>1)
using namespace std;
typedef long long lnt;
template <class T> inline void read(T &x) {
	x = 0; int c = getchar(), f = 1;
	for (; !isdigit(c); c = getchar()) if (c == 45) f = -1;
	for (; isdigit(c); c = getchar()) (x *= 10) += f*(c-'0');
}
int n, a[MAX_N+5], b[MAX_N+5];
int s[MAX_N+5], tr[MAX_N*2+5];
void inc(int p) {for (; p <= n*2+1; p += (p&-p)) tr[p]++;}
int sum(int p) {int ret = 0; for (; p; p -= (p&-p)) ret += tr[p]; return ret;}
bool chk(int x) {
	lnt tot = 0; memset(tr, 0, sizeof tr);
	for (int i = 1; i <= n; i++)
		s[i] = s[i-1]+(a[i] >= x ? 1 : -1);
	for (int i = 0; i <= n; i++)
		tot += sum(s[i]+n+1), inc(s[i]+n+1);
	return tot >= 1LL*n*(n+1)/4;
}
int bi_solve(int l, int r) {
	int ret = 0;
	while (l <= r)
		if (!chk(b[mid])) r = mid-1;
		else ret = mid, l = mid+1;
	return ret;
}
int main() {
	read(n); for (int i = 1; i <= n; i++) read(a[i]), b[i] = a[i];
	return sort(b+1, b+n+1), printf("%d\n", b[bi_solve(1, n)]), 0;
}
