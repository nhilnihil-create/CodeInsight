//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

string s, t;
ll n, m;
map<ll, char> mp;
set<ll> st;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> s >> t;
	ll l = n * m / __gcd(n, m);
	for (ll i = 0; i < n; i++)
		mp[i * (l / n) + 1] = s[i], st.insert(i * (l / n) + 1);
	for (ll i = 0; i < m; i++)
		if (st.count(i * (l / m) + 1) && mp[i * (l / m) + 1] != t[i])
			return cout << -1 << endl, 0;
	cout << l << endl;
	return 0;
}
