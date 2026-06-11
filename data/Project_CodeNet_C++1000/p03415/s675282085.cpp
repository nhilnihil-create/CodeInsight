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
	string ans;
	for (int i = 0; i < 3; i++)
	{
		string a;
		cin >> a;
		ans += a[i];
	}
	cout << ans << endl;
}

