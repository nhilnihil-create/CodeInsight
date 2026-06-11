#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;

	vector<ll> x(n + 1);
    for (ll i = 2; i <= n; ++i) {
        ll num = i;
    	for (ll j = 2; j <= num; ++j) {
	    	while (num%j == 0) {
		    	x.at(j)++;
			    num /= j;
    		}
    	}
    }

    ll res = 0;
    for (ll i = 2; i <= n; ++i) {
        if (x[i] >= 74) ++res;
        for (ll j = i + 1; j <= n; ++j) {
            if (x[i] >= 14 && x[j] >= 4) ++res;
            if (x[i] >= 4 && x[j] >= 14) ++res;
            if (x[i] >= 24 && x[j] >= 2) ++res;
            if (x[i] >= 2 && x[j] >= 24) ++res;
            for (ll k = j + 1; k <= n; ++k) {
                if (x[i] >= 4 && x[j] >= 4 && x[k] >= 2) ++res;
                if (x[i] >= 4 && x[j] >= 2 && x[k] >= 4) ++res;
                if (x[i] >= 2 && x[j] >= 4 && x[k] >= 4) ++res;
            }
        }
    }
    cout << res << endl;
}
