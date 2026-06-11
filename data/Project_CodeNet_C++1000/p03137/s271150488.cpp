#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

int		main(void)
{
	int n, m;
	cin >> n >> m;

	vector<ll> X(m);
	for (int i = 0; i < m; ++i)
		cin >> X[i];
	if (n >= m)
	{
		cout << 0 << endl;
		return 0;
	}
	sort(all(X));
	vector<ll> D(m-1);
	ll ans = 0;
	for (int i = 0; i < m-1; ++i)
	{
		D[i] = X[i+1] - X[i];
		ans += D[i];
	}
	sort(rall(D));
	for (int i = 0; i < n-1; ++i)
		ans -= D[i];
	cout << ans << endl;	
}

