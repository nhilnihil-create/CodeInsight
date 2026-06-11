#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
using ll = long long;
int main()
{
	int n;
	ll x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	ll count = 0;
	rep(i, n)
	{
		if (x >= a[i])
		{
			x -= a[i];
			count++;
		}
	}
	// 飴が余っていたら一人にだけあまりを全て与える。ほしい数ちょうどじゃないのでcount--
    if (count == n && x > 0) count--;
	cout << count << endl;
	return 0;
}