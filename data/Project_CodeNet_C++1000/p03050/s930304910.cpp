#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int INF = 101234567;

int main() {
    ll N;
    ll ans = 0;
    vector<ll>v;
    cin >> N;

    for (int k = 1; k < (double)sqrt(N); k++) {
        if (N % k == 0) {
            ll m = N/k - 1;
            if (m > k) {
                ans += m;
            }
        }
    }

    cout << ans << endl;
}
