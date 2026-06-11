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

const int N = 2e5 + 5;
int n, l, t, p;
ll ans;
int b[22];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> t;
        for (int k = 0; k <= 20; ++k) {
            if ((1 << k) & t) {
                l = max(l, b[k]);
                b[k] = i;
            }
        }
        ans += i - l;
    }

    cout << ans << endl;
    return 0;
}
