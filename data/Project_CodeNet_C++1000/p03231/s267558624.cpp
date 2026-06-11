#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
#define REP(i, n) for(int i=1;i<=n;i++)
typedef long long ll;

int main() {
	ll n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	ll l = n * m / __gcd(n, m);
	map<ll, char> mp;
	map<int, int> mp2;
	rep(i, n) {
		mp[i * (l / n)] = s[i];
		mp2[i * (l / n)]++;
	}
	rep(i, m) {
		if (mp2[i * (l / m)] != 0 && mp[i * (l / m)] != t[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << l << endl;
	return 0;
}