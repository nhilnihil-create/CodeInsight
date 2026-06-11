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
int n, m;
int a[N];
ll ans;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] -= i + 1;
    }
    sort(a, a + n);
    if (n & 1)
        m = a[n / 2];
    else
        m = (a[n / 2 - 1] + a[n / 2]) / 2;

    for (int i = 0; i < n; ++i) {
        ans += abs(a[i] - m);
    }

    cout << ans << endl;
    return 0;
}
