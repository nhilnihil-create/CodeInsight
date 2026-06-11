#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;
using P = pair<ll, ll>;

int main() {
	int N;
	cin >> N;
	vector<P> pos(N);
	for (int i = 0; i < N; i++) {
		cin >> pos[i].first >> pos[i].second;
	}

	int par = (abs(pos[0].first) + abs(pos[0].second)) % 2;
	for (int i = 0; i < N; i++) {
		ll x = pos[i].first, y = pos[i].second;

		int par2 = (abs(x) + abs(y)) % 2;
		pos[i] = P(x + y, x - y);

		if (par2 != par) {
			cout << -1 << endl;
			return 0;
		}
	}

	vector<ll> d;
	for (int i = 30; i >= 0; i--) {
		d.push_back(1LL<<i);
	}
	if (par % 2 == 0) d.push_back(1);
	cout << d.size() << endl;
	for (int i = 0; i < d.size(); i++) {
		cout << d[i];
		if (i != d.size() - 1) cout << " ";
		else cout << endl;
	}

	for (int i = 0; i < N; i++) {
		int xdir, ydir;
		ll xsum = 0, ysum = 0;
		for (int j = 0; j < d.size(); j++) {
			if (xsum <= pos[i].first) {
				xdir = 1;
				xsum += d[j];
			} else {
				xdir = -1;
				xsum -= d[j];
			}
			if (ysum <= pos[i].second) {
				ydir = 1;
				ysum += d[j];
			} else {
				ydir = -1;
				ysum -= d[j];
			}

			if (xdir == 1) {
				if (ydir == 1) cout << "R";
				else cout << "U";
			} else {
				if (ydir == 1) cout << "D";
				else cout << "L";
			}
		}
		cout << endl;
	}

	return 0;
}
