#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        ll a;
        cin >> a;
        res += a - 1;
    }
    cout << res << endl;
}
