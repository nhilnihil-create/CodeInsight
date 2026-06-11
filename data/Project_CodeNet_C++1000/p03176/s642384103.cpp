#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;

// ll dp[200010] = {0};
ll h[200010] = {0};
ll a[200010] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	// cin >> t;
	while(t != 0) {
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll base = 1;
		while(base <= n) {
			base *= 2;
		}

		// this question is solved using dp on segment trees
		vector<ll> tree(2*base);
		// dp stores values for height of flowers
		vector<ll> dp(n+1);

		for(int flower = 0; flower < n; flower++) {
			int x = h[flower] + base;
			// find the flower with given hight in tree

			ll best = 0;
			// go from leaf till root and whenever we are at right child, choose the left child
			while(x > 1) {
				if(x%2 == 1) {
					best = max(best, tree[x-1]);
				}
				x /= 2;
			}

			// for current height, get the previous best and current flower beauty
			dp[h[flower]] = best + a[flower];

			// update the tree
			for(int i = base + h[flower]; i >= 1; i /= 2) {
				tree[i] = max(tree[i], dp[h[flower]]);
			}
		}

		ll ans = 0;
		for(int i = 0; i <= n; i++) {
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	    t--;
	}
	return 0;
}
