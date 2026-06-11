#include<cstdio>
#include<cstring>
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

#define int long long

const int N = 4e5 + 5;

int seg[N], sum[N], a[N], n;

void add(int x)
{
	for (; x < N; x += x & -x)
		++seg[x];
}

int query(int x)
{
	int res = 0;
	for (; x; x -= x & -x)
		res += seg[x];
	return res;
}

bool check(int x)
{
	memset(seg, 0, sizeof(seg));
	sum[0] = 0;
	int res = 0;
	add(sum[0] + n + 1);
	
	for (int i = 1; i <= n; ++i) 
	{
		sum[i] = sum[i - 1] + (a[i] >= x ? 1 : -1);
		res += query(sum[i] + n + 1);
		add(sum[i] + n + 1);
	}
	
	if (res >= 1LL * n * (n + 1) / 2 - res) 
		return true;
	return false;
}

signed main()
{
	n = read();
	
	for (int i = 1; i <= n; ++i) a[i] = read();
	
	int l = 0, r = 1e9;
	while (l < r)
	{
		int mid = l + r + 1 >> 1;
		if (check(mid)) l = mid;
			else r = mid - 1;
	}
	
	printf("%d\n", l);
	
	return 0;
}
