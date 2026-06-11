#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>


using namespace std;

typedef long long ll;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
typedef pair<ll, ll> pll;


int main() {
	int n, k;
	cin >> n >> k;
	vector<pll> p(n);
	vector<ll>	x(n);
	vector<ll> y(n);
	for (int i = 0; i < n; i++) {
		
		cin >> x[i] >> y[i];
		p[i] = make_pair(x[i], y[i]);
	}

	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	ll ans = BIG_NUM * 5;

	for (int xi = 0;xi + k <=n;xi++) {
		for (int xj = xi + k - 1;xj < n;xj++) {
			ll dx = x[xj] - x[xi];


			for (int yi = 0;yi + k <=n;yi++) {
				for (int yj = yi + k - 1;yj < n;yj++) {
					ll dy = y[yj] - y[yi];

					int cnt = 0;
					for (int i = 0; i < n;i++) {
						if (x[xi] <= p[i].first &&p[i].first <= x[xj]
							&& y[yi] <= p[i].second && p[i].second <= y[yj]) {

							cnt++;
						}
					}
					if (cnt >= k) {
						ans = min(ans, dx*dy);
					}
						
				}
			}
		}
	}
	cout << ans << endl;
}

