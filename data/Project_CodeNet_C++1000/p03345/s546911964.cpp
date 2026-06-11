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
	ll A, B, C, K;
	cin >> A >> B >> C >> K;
	if (B == min({A, B, C}) || B == max({A, B, C}))
	{
		if (K%2 == 0)
			cout << A - B << endl;
		else
			cout << B - A << endl;
	}
	else if (K%2 == 0)
		cout << A - B << endl;
	else
		cout << C - B << endl;
}

