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
	int n;
	cin >> n;

	vpii E(1e5, pair<int, int>());
	vpii O(1e5, pair<int, int>());
	for (int i = 0; i < 1e5; i++)
	{
		E[i].second = i+1;
		O[i].second = i+1;
	}
	for (int i = 0; i < n; i++)
	{
		int v;
		cin >> v;
		i % 2 == 0 ? E[v-1].first++ : O[v-1].first++;
	}

	sort(rall(E));
	sort(rall(O));
	int ans;
	if (E[0].second == O[0].second)
	{
		if (E[1].first > O[1].first)
			ans = (n/2 - E[1].first) + (n/2 - O[0].first);
		else
			ans = (n/2 - E[0].first) + (n/2 - O[1].first);
	}
	else
		ans = (n / 2 - E[0].first) + (n / 2 - O[0].first);
	cout << ans << endl;
}

