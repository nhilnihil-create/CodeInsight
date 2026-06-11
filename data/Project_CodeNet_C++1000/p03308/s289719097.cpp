#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    ll max_diff = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            max_diff = max(max_diff, abs(a[i] - a[j]));
        }
    }
    cout << max_diff << endl;
}