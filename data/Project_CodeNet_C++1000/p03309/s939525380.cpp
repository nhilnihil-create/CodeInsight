#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//cout << fixed << setprecision(17) << res << endl;
 
int main() {
    ll n;
    cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        A[i] = a - (i+1);
    }
    sort(A.begin(), A.end());

    ll b = 0;
    if (n % 2 == 0) {
        b = A[n/2 - 1];
    } else {
        b = A[n / 2];
    }

    ll res = 0;
    for (auto a : A) {
        res += abs(a-b);
    }
    cout << res << endl;
}
