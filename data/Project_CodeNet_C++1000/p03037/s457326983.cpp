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
int a[N];
int n, m, l, r, res;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        a[l]++;
        a[r + 1]--;
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum == m) {
            ++res;
        }
    }
    cout << res << endl;
    return 0;
}
