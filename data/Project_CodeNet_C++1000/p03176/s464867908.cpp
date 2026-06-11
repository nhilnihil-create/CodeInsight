/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
    int n;
	scanf("%d", &n);
    int base = 1;
    while (base <= n) {
        base *= 2;
    }
    vector<ll> dp(n+1), bit(2*base);
    
	vector<int> h(n), a(n);
	
	for (int i=0; i<n; ++i) {
		scanf("%d", &h[i]);
	}

	for (int i=0; i<n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i=0; i<n; ++i) {
	    int tmp = base + h[i];
	    ll best = 0;
	    while (tmp > 1) {
	        if (tmp%2 == 1) {
	            if (bit[tmp-1] > best) {
	                best = bit[tmp-1];
	            }
	        }
	        tmp /= 2;
	    }
		dp[h[i]] = best + a[i];
		for (int j=base+h[i]; j>=1; j/=2 ) {
		    if (dp[h[i]] > bit[j]) {
		        bit[j] = dp[h[i]];
		    }
		}
	}
	ll ans = 0;
	for(int i=0; i<=n; i++) {
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	printf("%lld\n", ans);

}