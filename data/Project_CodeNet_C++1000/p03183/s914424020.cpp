#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define emp emplace

using namespace std;
using ll = long long;
using ii = pair<int, int>;

const int N = 1010, W = 10010;
ll pd[N][W];
int val[N];
int w[N], s[N];
int v[N];

bool cmp(int a, int b)
{
	return s[a] + w[a] > s[b] + w[b];
}

int main()
{
	int n;
	scanf("%d", &n);
	iota(v, v+n, 0);
	for (int i = 0; i < n; i++)
		scanf("%d %d %d", w+i, s+i, val+i);
	sort(v, v+n, cmp);
	for (int i = n-1; i >= 0; i--)
	{
		int a = v[i];
		for (int j = 0; j < w[a]; j++)
			pd[i][j] = pd[i+1][j];
		for (int j = w[a]; j < W; j++)
			pd[i][j] = max(pd[i+1][j], val[a] + pd[i+1][min(j - w[a], s[a])]);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, val[v[i]] + pd[i+1][s[v[i]]]);
	printf("%lld\n", ans);
	return 0;
}