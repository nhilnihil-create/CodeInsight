#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll n;
	cin >> n;
	vector<string>s(n);
	ll mcount = 0;
	ll acount = 0;
	ll rcount = 0;
	ll ccount = 0;
	ll hcount = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i][0] == 'M') {
			mcount++;
		}
		if (s[i][0] == 'A') {
			acount++;
		}
		if (s[i][0] == 'R') {
			rcount++;
		}
		if (s[i][0] == 'C') {
			ccount++;
		}
		if (s[i][0] == 'H') {
			hcount++;
		}
	}
	int count[5] = { mcount,acount,rcount,ccount,hcount };
	ll ans = 0;
	ll check = 0;
	ll sum = 0;
	for (int bit = 0; bit < (1 << 5); bit++) {
		sum = 1;
		check = 0;
		for (int i = 0; i < 5; i++) {
			if (bit & (1 << i)) {
				check++;
				sum *= count[i];
			}
		}
		if (check == 3) {
			ans += sum;
		}
	}
	cout << ans << endl;
}

