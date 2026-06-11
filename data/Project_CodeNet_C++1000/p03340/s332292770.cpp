#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <map>

#define rep(i,n) for(int i = 0; i < (n); ++i)

#define debug(vec) for(auto v : vec) cout << v << " "; cout << endl;

#define debug2D(vec2D) for(auto vec : vec2D) { for (auto v : vec) cout << v << " "; cout << endl; } 

using namespace std;

typedef long long ll;

const long long int INF = 1 << 29; //<10^10
//const ll MOD = 998244353;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

  int n;
	cin >> n;

	vector<ll> a(n);

	rep(i, n) {
		cin >> a[i];
	}

	ll ans = 0;
	int r = 0, syaku = a[0];
	rep(l, n) {
		while (r + 1 < n && (syaku & a[r+1]) == 0) {
			syaku += a[r+1];
			r++;
		}
		ans += (ll) r-l+1;
		syaku -= a[l];
	}

	std::cout << ans << endl;
}
