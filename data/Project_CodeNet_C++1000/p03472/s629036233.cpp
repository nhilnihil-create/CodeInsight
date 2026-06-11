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

const int N = 1e5 + 5;
int n, m;
int a[N], b[N];
ll sum;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());
    for (int i = 0; i < n; ++i) {
        if (b[i] <= a[0]) {
            m -= sum;
            cout << (m + a[0] - 1) / a[0] + i << endl;
            exit(0);
        }
        sum += b[i];
        if (sum >= m) {
            cout << i + 1 << endl;
            exit(0);
        }
    }
    m -= sum;
    cout << (m + a[0] - 1) / a[0] + n << endl;
    return 0;
}
