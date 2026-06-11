#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	int N, M;
	cin >> N >> M;
	vpii Islands(M, pair<int, int>());
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		Islands[i].first = b;
		Islands[i].second = a;
	}
	sort(all(Islands));
	int ans = 0, broke = -1;
	for (int i = 0; i < M; i++)
	{
		int W = Islands[i].second;
		int E = Islands[i].first;
		if (broke < W)
		{
			broke = E-1;
			ans++;
		}
	}
	cout << ans << endl;
}

