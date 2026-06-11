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
    int n[4];
    rep(i, 4) { cin >> n[i]; }

    int memo[4] = {1, 9, 7, 4};
    sort(n, n + 4);
    sort(memo, memo + 4);

    rep(i, 4) {
        if (n[i] != memo[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}

