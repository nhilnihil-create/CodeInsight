#include "bits/stdc++.h"

using namespace std;
using ll = long long;
using ull = unsigned long long;

typedef pair< long long, long long > P;
typedef pair< long long, P > PP;
typedef pair< P, P > PPP;

const double DINF = 5e14, eps = 1e-10;
const long long MOD = 1e9 + 7, INF = 5e18;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };

#define fr first
#define sc second
#define pb push_back
#define eb emplace_back
#define ALL(x) (x).begin(),(x).end()

ll n, x[1010], y[1010];
bool fl;

int main() {
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> x[i] >> y[i];
		if (!i)fl = abs(x[i] + y[i]) % 2 ? 1 : 0;
		else {
			if (abs(x[i] + y[i]) % 2 && !fl) {
				cout << -1 << endl;
				return 0;
			}
			if (!(abs(x[i] + y[i]) % 2) && fl) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	vector<ll> d;
	for (int i = 30; i >= 0; i--) d.push_back(1LL << i);
	if (!fl) d.push_back(1);
	cout << d.size() << endl;
	for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++) {
		ll xt = x[i], yt = y[i];
		ll x = 0, y = 0;
		for (int j = 0; j < (int)d.size(); j++) {
			if (abs(x - xt) >= abs(y - yt)) {
				if (x >= xt) x -= d[j], cout << "L";
				else x += d[j], cout << "R";
			}
			else {
				if (y >= yt) y -= d[j], cout << "D";
				else y += d[j], cout << "U";
			}
		}
		cout << endl;
	}
	return 0;
}
