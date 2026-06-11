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

const int N = 1e5 + 5;
int n, m, c, t, ans;

int main() {
    cin >> n >> m;
    ans = 2000;
    for (int i = 0; i < n; ++i) {
        cin >> c >> t;
        if (t <= m) {
            ans = min(c, ans);
        }
    }
    if (ans == 2000)
        cout << "TLE" << endl;
    else
        cout << ans << endl;
    return 0;
}
