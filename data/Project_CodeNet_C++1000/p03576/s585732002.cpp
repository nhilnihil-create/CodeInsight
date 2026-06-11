
// D - Axis-Parallel Rectangle

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

vector<pair<ll, ll>> p;
set<ll> x_set, y_set;
vector<ll> x_vec, y_vec;

int main() {
	int N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		ll x, y;
		cin >> x >> y;
		p.push_back(make_pair(x, y));
		x_set.insert(x);
		y_set.insert(y);
	}

	x_vec = vector<ll>(x_set.begin(), x_set.end());
	y_vec = vector<ll>(y_set.begin(), y_set.end());

	ll ans = INF;

	for (int i1=0; i1<x_vec.size(); i1++) {
		for (int i2=i1+1; i2<x_vec.size(); i2++) {
			for (int j1=0; j1<y_vec.size(); j1++) {
				for (int j2=j1+1; j2<y_vec.size(); j2++) {
					ll x1 = x_vec[i1];
					ll y1 = y_vec[j1];
					ll x2 = x_vec[i2];
					ll y2 = y_vec[j2];

					int cnt = 0;
					for (int k=0; k<N; k++) {
						ll x = p[k].first;
						ll y = p[k].second;
						if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
							cnt++;
						}
					}

					if (cnt >= K) ans = min(ans, (x2 - x1) * (y2 - y1));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}