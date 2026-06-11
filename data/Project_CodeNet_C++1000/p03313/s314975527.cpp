#include <bits/stdc++.h>
using namespace std;

const int N = (1 << 19) + 10;
int n, m, a[N], ans[N], mvp[N], bin[30];

template <class T> inline void in(T &x) {
	x = 0; int f = 0; char ch = getchar();
	for (; ch<'0' || ch>'9';) {if (ch=='-') f=-1; ch = getchar();}
	for (; ch>='0' && ch<='9';) x = x*10 + ch-'0', ch = getchar();
	x = f ? -x : x;
}

int main() {
	in(m), bin[0] = 1;
	for (int i = 1; i < 30; ++i) bin[i] = bin[i - 1] << 1;
	n = bin[m];
	for (int i = 0; i < n; ++i) in(a[i]);
	for (int i = 0; i < n; ++i)
		for (int j = i; j < n; j = (j + 1) | i)
			ans[j] = max(ans[j], mvp[j] + a[i]), mvp[j] = max(mvp[j], a[i]);
	for (int i = 1; i < n; ++i) printf("%d\n", ans[i] = max(ans[i], ans[i - 1]));
	return 0;
}