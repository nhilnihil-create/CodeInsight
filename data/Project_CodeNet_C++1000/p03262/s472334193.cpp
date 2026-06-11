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
int a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = m;
    sort(a, a + n + 1);
    int d = a[1] - a[0];
    for (int i = 1; i <= n; ++i) {
        d = __gcd(d, a[i] - a[i - 1]);
    }
    cout << d << endl;
    return 0;
}
