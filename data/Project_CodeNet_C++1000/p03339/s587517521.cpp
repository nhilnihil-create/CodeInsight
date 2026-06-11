#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> L(n+2,0);
    vector<ll> R(n+2,0);
    ll l = 0;
    ll cur = 0;
    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'W') ++cur;
        L[i+1] = cur;
    }
    cur = 0;
    for (ll i = n-1; i >= 0; --i) {
        if (s[i] == 'E') ++cur;
        R[i+1] = cur;
    }

    ll res = 1e9;
    for (ll i = 1; i <= n; ++i) {
        res = min(res, L[i-1] + R[i+1]);
    }
    cout << res << endl;

}
