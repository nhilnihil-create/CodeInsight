#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int n, m;
	string s, t;
	cin >> n >> m;
	cin >> s >> t;
	long long int x = lcm(n, m);

	int sidx = 0;
	int tidx = 0;
	long long int snum = 1;
	long long int tnum = 1;
	long long int ans = x;
	while (sidx < n && tidx < m) {
		if (snum == tnum) {
			if (s[sidx] != t[tidx]) {
				ans = -1;
				break;
			}
		}
		if (snum < tnum) {
			snum = ++sidx * (x / n);
		}
		else {
			tnum = ++tidx * (x / m);
		}
	}
	cout << ans << endl;
}
