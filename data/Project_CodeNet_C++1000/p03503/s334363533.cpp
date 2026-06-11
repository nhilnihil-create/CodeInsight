#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> open(n, vector<int>(10));
	vector<vector<ll>> p(n, vector<ll>(11));
	rep(i, n) {
		rep(j, 10) {
			cin >> open[i][j];
		}
	}
	rep(i, n) {
		rep(j, 11) {
			cin >> p[i][j];
		}
	}

	ll ans = -10000000000;
	for (int bit = 1; bit < (1 << 10); bit++) {
		ll ansi = 0;
		rep(i, n) {
			int cnt = 0;
			rep(j, 10) {
				if ((bit >> j) & open[i][j]) cnt++;
			}
			ansi += p[i][cnt];
		}
		ans = max(ans, ansi);
	}
	cout << ans << endl;
}