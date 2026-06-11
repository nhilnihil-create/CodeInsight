#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;

    ll last = 0;
    set<ll> S;
    for (ll i = 0; i < k && a + i <= b; ++i) {
        S.insert(a+i);
    }
    for (ll i = 0; i < k && b - i >= a; ++i) {
        S.insert(b-i);
    }
    for (auto s : S) {
        cout << s << endl;
    }
}
