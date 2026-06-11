#include <bits/stdc++.h>

#define ll long long int

using namespace std;

int main() {
    string s;
    cin >> s;
    ll k;
    cin >> k;

    set<string> t;

    ll n = s.size();
    for (ll i = 0; i < n; ++i) {
        for (ll j = 1; j <= k && i + j <= n; ++j) {
            // cerr << s.substr(i, j) << endl;
            t.insert(s.substr(i, j));
        }
    }

    auto iter = t.begin();
    for (ll i = 1; i < k; ++i) {
        ++iter;
    }

    cout << *iter << endl;
}
