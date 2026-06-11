#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int minum = 104;
const int MAX = 200;

int main() {
    ll ans = 0;
    ll N;
    cin >> N;

    if (N <= minum) ;
    else if (N == 105) ans = 1;
    else {
        ans++;
        for (ll i = 107; i <= N; i += 2) {
            ll div = 0;
            for(ll j = 1; j <= i; j += 2) {
                if (i % j == 0) div++;
            }
            if (div == 8) {
                ans++;
                // cout << i << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
