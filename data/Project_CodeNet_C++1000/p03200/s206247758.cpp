//Practice
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 2e5 + 5;
const ll INF = 1e9 + 5;
const ll mxN = 1000000007;
const double E = 1e-9;

//------------------------------------------------------------------------------
string s;
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	/*ifstream cin("input.txt");
	ofstream cout("output.txt");*/
	cin >> s;
	ll cnt = 0, ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[s.size() - 1 - i] == 'B')
		{
			ans += i - cnt;
			// cout<<i<<" "<<ans<<"\n";
			++cnt;
		}
	}
	cout << ans;
	return 0;
}
//29-08-2020 13:01:13
//------------------------------------------------------------------------------