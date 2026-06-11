#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 1e5 + 5;
const int P = 1e9 + 7;
int a[N], inv[N];

int Pow(int x, int t)
{
	int res = 1;
	for (; t; t >>= 1, x = 1LL * x * x % P)
		if (t & 1) res = 1LL * res * x % P;
	return res;
}

int main()
{
	int n = read(), ans = 0;
	for (int i = 1; i <= n; ++i) a[i] = read();
	for (int i = 1; i <= n; ++i) inv[i] = Pow(i, P - 2);
	for (int i = 1; i <= n; ++i) (inv[i] += inv[i - 1]) %= P;
	for (int i = 1; i <= n; ++i) (ans += 1LL * a[i] * (inv[i] + inv[n - i + 1] - 1) % P) %= P;
	for (int i = 1; i <= n; ++i) ans = 1LL * ans * i % P;
	printf("%d\n", ans); 
	return 0;
}
