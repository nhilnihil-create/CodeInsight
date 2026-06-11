#include <bits/stdc++.h>

#define repd(i, a, b) for (ll i = (a); i < (b); i++)
#define repb(i, n) for (ll i = (n)-1; i >= 0; i--)
#define rep(i, n) repd(i, 0, n)

using namespace std;

using ll = long long;
using ul = unsigned long long;
using ld = long double;
ll mod = 1000000007;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = s.length();

    bool result = false;

    rep(i, n) {
        string temp = s.substr(n - i) + s.substr(0, n - i);
        if (temp == t)
            result = true;
    }

    if (result) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}

