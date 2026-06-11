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
int n, m, k;
ll ans;
int a[N], b[N], c[N];
ll psum[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    sort(c, c + n);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && b[i] > a[j])
            ++j;
        psum[i] = j;
    }
    for (int i = 1; i < n; ++i) {
        psum[i] += psum[i - 1];
    }
    j = 0;
    for (int i = 0; i < n; ++i) {
        while (j < n && c[i] > b[j])
            ++j;
        if (j > 0)
            ans += psum[j - 1];
    }

    cout << ans << endl;
    return 0;
}
