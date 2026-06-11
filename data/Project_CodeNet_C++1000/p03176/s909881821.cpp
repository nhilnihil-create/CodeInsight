#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll count(vector<ll>& bit, ll i) {
    i++;
    ll s = 0;
    while (i > 0) {
        if (bit[i] > s) {
            s = bit[i];
        }
        i -= i&(-i);
    }
    return s;
}

void update(vector<ll>& bit, ll i, ll v) {
    i++;
    while (i < bit.size()) {
        if (v > bit[i]) {
            bit[i] = v;
        }
        i += i&(-i);
    }
}

int main() {
    int n;
	scanf("%d", &n);
    
    vector<ll> dp(n+1), bit(n+2);
    
	vector<ll> h(n), a(n);
	
	for (int i=0; i<n; ++i) {
		scanf("%d", &h[i]);
	}

	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i=0; i<n; ++i) {
	    ll tmp = count(bit, h[i]) + a[i];
	   // cout << tmp << " "<< count(bit, h[i]) << '\n';
	    if (tmp > dp[h[i]]) {
	        dp[h[i]] = tmp;
	    }
	    update(bit, h[i], dp[h[i]]);
	}
	ll ans = 0;
	for(int i=0; i<=n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	printf("%lld\n", ans);

}