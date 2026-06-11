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
int n, m, k, ans;
int cnt[N];
int a[N];
int idx;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> m;
        ++cnt[m];
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] != 0) {
            a[idx++] = cnt[i];
        }
    }
    sort(a, a + idx);
    for (int i = 0; i < idx - k; ++i) {
        ans += a[i];
    }
    cout << ans << endl;
    return 0;
}
