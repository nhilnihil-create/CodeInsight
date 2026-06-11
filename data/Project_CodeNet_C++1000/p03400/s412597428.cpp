#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, d, x;
	cin >> n >> d >> x;
	vector<int> as(n);
	for (auto &&a : as)
	{
		cin >> a;
	}

	int ans = x;
	for (auto &&a : as)
	{
		ans += (d + a - 1) / a;
	}

	cout << ans << endl;

	return 0;
}