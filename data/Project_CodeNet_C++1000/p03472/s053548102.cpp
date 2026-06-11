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
	int N, H;
	cin >> N >> H;

	vpii katana(N, pair<int, int>(0, 0));
	for (int i = 0; i < N; i++)
		cin >> katana[i].second >> katana[i].first;

	sort(rall(katana));
	int K = 0;
	for (int i = 1; i < N; i++)
	{
		int a = katana[i].second;
		int b = katana[i].first;
		if (a == katana[K].second)
		{
			if (b < katana[K].first)
				K = i;
		}
		else if (a > katana[K].second)
			K = i;
	}

	int mx_a = katana[K].second;
	int ans = 0;
	for (int c = 0; c < N && H > 0; c++)
	{
		int b = katana[c].first;
		if (b > mx_a)
		{
			H -= b;
			ans++;
		}
	}
	if (H <= 0)
		cout << ans << endl;
	else if (H % mx_a == 0)
		cout << ans + H / mx_a << endl;
	else
		cout << ans + H / mx_a + 1 << endl;
}












