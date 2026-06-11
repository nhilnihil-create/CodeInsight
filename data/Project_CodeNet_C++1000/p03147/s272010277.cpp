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

int n, t, p, res;
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> t;
        if (t < p) {
            res += p - t;
        }
        p = t;
    }
    res += p;
    cout << res << endl;
    return 0;
}
