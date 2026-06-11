#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

const int mod = 1000000007;
signed main(void)
{
	map<char, int> mp;
	long long ans;
	int n;
	string s;

	cin >> n >> s;
	rep(i, n)
	{
		mp[s[i]]++;
	}
	ans = 1;
	for(auto p : mp)
	{
		auto v = p.second;
		ans *= (v + 1);
		ans %= mod;
	}
	cout << ans - 1 << endl;
	return 0;
}
