#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
//
ll n;
vector<ll>a;
vector<vector<ll>>dp;
//

ll F(ll idx, ll k)
{
	if (k < 0)
		return 0;
	if (idx == n)
		return (k == 0);
	if (dp.at(idx).at(k) != -1)
		return dp.at(idx).at(k);
	ll aa = F(idx, k - 1);
	ll bb = F(idx + 1, k - a.at(idx) - 1);
	ll cc = F(idx + 1, k);
	ll ans = (aa - bb + cc) % MOD;
	ans = (ans + MOD) % MOD;
	return (dp.at(idx).at(k) = ans);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	ll k; cin >> n >> k;
	a = vector<ll>(n);
	for (auto &it : a)
		cin >> it;
	dp = vector<vector<ll>>(n, vector<ll>(k + 1, -1));
	cout << F(0, k);

	return 0;
}