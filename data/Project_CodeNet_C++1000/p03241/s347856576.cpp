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
int n, m, k, ans;

int main() {
    cin >> n >> m;
    for (int i = 1; i * i <= m; ++i) {
        if (m % i == 0) {
            if (m / i >= n)
                ans = max(i, ans);
            if (i >= n)
                ans = max(m / i, ans);
        }
    }
    cout << ans << endl;
    return 0;
}
