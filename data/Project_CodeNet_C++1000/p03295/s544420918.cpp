#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool compare(pair<ll, ll> a, pair<ll, ll> b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
int main()
{

	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt" , "r" , stdin);
// 	freopen("output.txt" , "w" , stdout);
// #endif

	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>>v;
	for (ll i = 1; i <= m; i++)
	{
		ll a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	sort(v.begin(), v.end(), compare);
	ll ans = 1, pa = v[0].first, pb = v[0].second;
	for (ll i = 1; i < m; i++)
	{
		if (v[i].first >= pb)
		{
			ans += 1;
			pb = v[i].second;
		}
		else
		{
			pb = min(v[i].second, pb);
		}
	}
	cout << ans << endl;



}
