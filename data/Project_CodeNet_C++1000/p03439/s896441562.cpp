#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 10000000000000000;
const ll mod = 1000000007;
ll test[1234][1234];
signed main() {
	ll n = 0, mae = 0, ato = 0; string maes = "", atos = "";
	cin >> n; ato = n;
	cout << 0 << endl << flush; cin >> maes;
	if (maes == "Vacant") { return 0; }
	for (int h = 0; h < 20; h++) {
		string s; ll naka = (mae + ato) / 2;
		cout << naka << endl << flush; cin >> s;
		if (s == "Vacant") { return 0; }
		if ((naka - mae) % 2 == 1) {
			if (maes == s) {
				atos = s; ato = naka;
			}
			else {
				maes = s; mae = naka;
			}
		}
		else {
			if (maes == s) {
				maes = s; mae = naka;
			}
			else {
				atos = s; ato = naka;
			}
		}
	}
	cin >> n; return 0;
}