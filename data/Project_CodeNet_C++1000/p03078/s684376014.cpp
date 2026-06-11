#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9+7, A = 1e3+5;

int main()
{
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	ll a[x], b[y], c[z], ab[x * y];
	for (int i = 0; i < x; cin >> a[i++]);
	for (int i = 0; i < y; cin >> b[i++]);
	for (int i = 0; i < z; cin >> c[i++]);

	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
			ab[i * y + j] = a[i] + b[j];
	sort(ab, ab + x * y, greater<ll>());

	vector<ll> ans;
	for (int i = 0; i < min(k, x * y); i++)
		for (int j = 0; j < z; j++)
			ans.pb(ab[i] + c[j]);

	sort(ans.rbegin(), ans.rend());
	for (int i = 0; i < k; i++)
		cout << ans[i] << '\n';
	return 0;
}