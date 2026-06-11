#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const ll INF = 1000000000000000000;
const ll mod = 1000000007;
signed main() {
	ll q, n; cin >> n;
    for (int i = 1; i <= 3500; i++) {
        for (int j = 1; j <= 3500; j++) {
            ll bunbo = n * i * j;
            ll bunsi = 4 * i * j - n * j - n * i;
            if (bunsi > 0 && bunbo % bunsi == 0) {
                cout << i << ' ' << j << ' ' << bunbo / bunsi << endl; return 0;
            }
        }
    }
	return 0;
}