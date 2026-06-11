#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i;
    }
    sort(a.begin(), a.end());
    const ll bCand[3] = {a[n / 2], a[n / 2 + 1], a[n / 2 - 1]};

    ll res[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            res[j] += abs(a[i] - bCand[j]);
        }
    }
    cout << min(min(res[0], res[1]), res[2]) << endl;
}