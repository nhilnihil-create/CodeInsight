#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll n, d, x;
    cin >> n >> d >> x;
    vector<ll> A(n);
    for (auto & a : A) cin >> a;

    ll res = x;
    for (auto a : A) {
        res += 1 + ((d-1)/a);
    }

    cout << res << endl;
}
