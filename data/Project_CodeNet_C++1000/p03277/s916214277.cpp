#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define file(x) freopen(#x".in", "r", stdin), freopen(#x".out", "w", stdout)

inline int read()
{
	int data = 0, w = 1; char ch = getchar();
	while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
	if (ch == '-') w = -1, ch = getchar();
	while (ch >= '0' && ch <= '9') data = data * 10 + (ch ^ 48), ch = getchar();
	return data * w;
}

const int N(1e5 + 10);
int n, m, a[N], sum[N], b[N], c[N];
void Add(int x) { for (; x <= m; x += x & -x) ++c[x]; }
int Sum(int x) { int s = 0; for (; x; x -= x & -x) s += c[x]; return s; }
int check(int mid)
{
	sum[0] = 0;
	for (int i = 1; i <= n; i++) sum[i] = (a[i] <= mid ? -1 : 1);
	for (int i = 1; i <= n; i++) sum[i] += sum[i - 1]; m = 0;
	for (int i = 0; i <= n; i++) b[++m] = sum[i];
	std::sort(b + 1, b + m + 1), m = std::unique(b + 1, b + m + 1) - b - 1;
	for (int i = 0; i <= n; i++)
		sum[i] = std::lower_bound(b + 1, b + m + 1, sum[i]) - b;
	long long ans = 0, all = 1ll * n * (n + 1) / 2; memset(c, 0, (m + 1) << 2);
	for (int i = 0; i <= n; i++) ans += Sum(sum[i]), Add(sum[i]);
	return ans >= all - ans;
}

int main()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int l = 1, r = 1e9, ans;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) l = mid + 1;
		else ans = mid, r = mid - 1;
	}
	printf("%d\n", ans);
	return 0;
}
