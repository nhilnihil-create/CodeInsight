#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int, int> ii;
#define DEBUG freopen("in.txt", "r", stdin);

struct fastio {
    fastio() {
        ios::sync_with_stdio(false);
        cout << setprecision(10) << fixed;
        cin.tie(0);
    }
};

fastio _fast_io;

ll n, b, base;

int main() {
    string ans = "";
    cin >> n;
    base = 2;
    if (n == 0) {
        cout << 0 << endl;
        exit(0);
    }

    while (n) {
        if (n % base) {
            ans = '1' + ans;
            ll v = pow(2, b);
            if (b & 1) {
                n += v;
            } else {
                n -= v;
            }
        } else {
            ans = '0' + ans;
        }
        ++b;
        base *= 2;
    }
    cout << ans << endl;

    return 0;
}
