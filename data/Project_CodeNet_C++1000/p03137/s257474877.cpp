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
int n, m, sum;
int a[N];
int d[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }
    sort(a, a + m);
    for (int i = 0; i < m - 1; ++i) {
        d[i] = a[i + 1] - a[i];
    }
    sort(d, d + m - 1, greater<int>());
    for (int i = n - 1; i < m - 1; ++i) {
        sum += d[i];
    }
    cout << sum << endl;
    return 0;
}
