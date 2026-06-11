#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<string, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>v(n);
	rep(i, n) {
		cin >> v[i];
	}
	ll ans(0);
	rep(l, k+1) {
		rep(r, k - l+1) {
			vector<ll>have;
			int d = k - r - l;
			if (l + r > n)continue;
			rep(i, l)have.push_back(v[i]);
			rep(j, r)have.push_back(v[n - j - 1]);
			sort(have.begin(), have.end());
			rep(p, d) {
				if (p >= have.size())break;
				if (have[p] < 0)have[p] = 0;
			}
			ll can(0);
			rep(p,have.size()) {
				can += have[p];
			}
			ans = max(ans, can);
		}
	}
	cout << ans;
	return 0;
	return 0;
}