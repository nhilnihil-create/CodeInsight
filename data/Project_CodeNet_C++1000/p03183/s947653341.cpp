#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3 + 5;
const long long INF = 1e16;

struct tow
{
	int w, s, v;
	double tr;

	bool operator<(tow other) const
	{
		return w + s < other.w + other.s;
	}
};

int n;
tow a[MAXN];
int sr, br;

void read_input()
{
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a[i].w, &a[i].s, &a[i].v);
		a[i].tr = 1.00 * a[i].w / a[i].s;
		sr = max(a[i].s, sr);
		br = max(a[i].w, br);
	}

	sort(a, a + n);
}

long long T[MAXN][MAXN * 10];

void solve()
{
	long long ans = 0;
	for(int i = 0; i <= sr + br; i++)
	{
		T[0][i] = -INF;
	}
	T[0][0] = 0;
	T[0][a[0].w] = a[0].v;
	ans = a[0].v;
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j <= sr + br; j++)
		{
			T[i][j] = T[i - 1][j];
		}
		for(int j = a[i].w; j <= sr + br; j++)
		{
			if(a[i].s >= j - a[i].w)
			T[i][j] = max(T[i][j], T[i - 1][j - a[i].w] + a[i].v);
			ans = max(ans, T[i][j]);
		}
	}
	printf("%lld\n", ans);
}

int main()
{
	read_input();
	solve();

	return 0;
}
