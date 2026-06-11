#include <bits/stdc++.h>
using namespace std;

const int B = 131, P[] = {1000000007, 1000000009};
typedef long long ll;
int n;
ll ans;
pair<pair<int, int>, pair<int, int> > l[1 << 18];
char s[40];

int main()
{
	scanf("%d%s", &n, s);
	for (int i = 0; i < 1 << n; i++)
	{
		int h1[2] = {}, h2[2] = {};
		for (int k = 0; k < 2; k++)
			for (int j = 0; j < n; j++)
				if (i >> j & 1) h1[k] = (1ll * h1[k] * B + s[j]) % P[k];
				else h2[k] = (1ll * h2[k] * B + s[j]) % P[k];
		l[i] = make_pair(make_pair(h1[0], h2[0]), make_pair(h1[1], h2[1]));
	}
	sort(l, l + (1 << n));
	for (int i = 0; i < 1 << n; i++)
	{
		int h1[2] = {}, h2[2] = {};
		for (int k = 0; k < 2; k++)
			for (int j = n - 1; j >= 0; j--)
				if (i >> j & 1) h1[k] = (1ll * h1[k] * B + s[n + j]) % P[k];
				else h2[k] = (1ll * h2[k] * B + s[n + j]) % P[k];
		ans += upper_bound(l, l + (1 << n), make_pair(make_pair(h1[0], h2[0]), make_pair(h1[1], h2[1])))
			- lower_bound(l, l + (1 << n), make_pair(make_pair(h1[0], h2[0]), make_pair(h1[1], h2[1])));
	}
	printf("%lld\n", ans);
	return 0;
}
