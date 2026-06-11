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

ll calc(ll A)
{
	if (A <= 0)
		return 0;
	// 10^3 <= 2^10
	// 1000 <= 1024
	// 10^12 <= 2^40
	// 10^12 <= 2進数 40桁くらい

	ll ans = 0;
	for (int i = 0; i < 50; i++)
	{
		// 0桁目　→　周期2
		// 1				4
		// 2				8
		// 3				16
		ll loop = (1LL << (i+1));
		ll cnt = (A / loop) * (loop / 2);
		cnt += max(0LL, (A % loop) - (loop / 2) + 1);

		// その桁の1の数が奇数だったら足し算
		if (cnt % 2 == 1)
			ans += 1LL << i;
	}
	return ans;
}

int		main(void)
{
	ll A, B;
	cin >> A >> B;
	ll ans = calc(B) ^ calc(A - 1);
	cout << ans << endl;
}

