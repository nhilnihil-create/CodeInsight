#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {

	ll n; cin >> n;
	const ll p = 100001;
	vector<ll> aNum(p, 0), bNum(p, 0);
	for (ll i = 0; i < n; i++) {
		ll v; cin >> v;
		if (i % 2 == 0) {
			aNum[v]++;
		}		
		else {
			bNum[v]++;
		}
	}
	ll a_first;
	ll b_first;
	ll tmpA = 0;
	ll tmpB = 0;
	for (ll i = 0; i < p; i++) {
		if (chmax(tmpA, aNum[i])) {
			a_first = i;
		}
		if (chmax(tmpB, bNum[i])) {
			b_first = i;
		}
	}
	sort(aNum.begin(), aNum.end(), greater<ll>());
	sort(bNum.begin(), bNum.end(), greater<ll>());
	ll a_first_cnt = aNum[0];
	ll b_first_cnt = bNum[0];
	ll a_second_cnt = aNum[1];
	ll b_second_cnt = bNum[1];

	if (a_first != b_first) {
		cout << n - a_first_cnt - b_first_cnt << endl;
	}
	else { // a_first == b_first
		cout << min(n - a_first_cnt - b_second_cnt, n - a_second_cnt - b_first_cnt) << endl;
	}
	return 0;
}