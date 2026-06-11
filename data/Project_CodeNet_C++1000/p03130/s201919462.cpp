#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    map<ll, ll> m;
    for (ll i = 0;i < 6;++i) {
        ll a;
        cin >> a;
        m[a]++;
    }
    for (auto p : m) {
        if (p.second > 2) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}