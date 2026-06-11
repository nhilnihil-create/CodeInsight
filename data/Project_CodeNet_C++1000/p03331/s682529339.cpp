#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
ll calc(int n)
{
	int res = 0;
	while (n > 0)
	{
		res += n % 10;
		n /= 10;
	}
	return res;
}

int main()
{
	int n;
	scanf("%d", &n);
	ll res = inf;
	for (ll i = 1; i < n; ++i) //n = i + jとして全探索
	{
		ll j = n - i;
		ll tmp = calc(i) + calc(j);
		res = min(res, tmp);
	}
	cout << res << endl;
	return 0;
}