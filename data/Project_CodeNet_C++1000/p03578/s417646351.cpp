#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int n;
	cin >> n;
	map<int, int> dcnt;
	rep(i, n) {
		int d;
		cin >> d;
		dcnt[d]++;
	}
	int m;
	cin >> m;
	map<int, int> mcnt;
	rep(i, m) {
		int t;
		cin >> t;
		mcnt[t]++;
	}
	bool ok = true;
	for (auto a : mcnt) {
		int t = dcnt[a.first];
		if (a.second > t) ok = false;
	}
	cout << (ok ? "YES" : "NO") << endl;
	return 0;
}