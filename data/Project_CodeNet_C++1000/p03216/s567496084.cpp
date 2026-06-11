#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	string s; cin >> s;
	ll q; cin >> q;
	vector<ll> ks(q);
	for (int i = 0; i < q; ++i) cin >> ks[i];
	for (auto k : ks) {
		ll ans = 0;
		ll d = 0;
		ll m = 0;
		ll cnt = 0;
		for (int i = 0; i < n; ++i)
		{
			if (i >= k) {
				if (s[i-k] == 'D') {
					cnt -= m;
					d--;
				}
				else if (s[i-k] == 'M') {
					m--;
				}
			}

			if (s[i] == 'D') d++;
			else if (s[i] == 'M') {
				m++;
				cnt += d;
			}
			else if (s[i] == 'C') ans += cnt;
		}

		cout << ans << endl;
	}
	return 0;
}