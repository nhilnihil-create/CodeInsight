/*The woods are lovely, dark and deep,
But I have promises to keep,
And miles to go before I sleep,
And miles to go before I sleep.*/

//PRABHJOT SINGH A.K.A. PRABHI
//~~~~~conquizztador~~~~~


#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int MOD = 1000000007;
const int MOD1 = 998244353;
const int maxn = 100010;
const int lim = (int)1e9;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;
	cin >> k;
	vector<lli> a(k);
	for (auto &i : a)
		cin >> i;
	lli l = 2ll, r = 2ll;
	for (int i = k - 1; i >= 0; --i)
	{
		lli t = a[i];
		l += ((t - l % t) % t); r -= (r % t);
		if (l > r)
		{
			cout << "-1" << endl; return 0;
		}
		r += (t - 1);
	}
	cout << l << " " << r << endl;
}