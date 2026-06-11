#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

static inline ll f(ll x) {
    if (x == -1) return 0;
    if (x % 4 == 0) return x;
    if (x % 4 == 1) return 1;
    if (x % 4 == 2) return x + 1;
    return 0;
}

ll a, b;
int main() {
    cin >> a >> b;
    cout << (f(b) ^ f(a - 1)) << endl;
    return 0;
}
