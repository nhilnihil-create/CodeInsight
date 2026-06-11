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
int n, m, p, y;
vector<int> a[N];
int cnt[N];
ll ans[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> p >> y;
        a[i] = {y, p, i};
    }
    sort(a, a + m);
    for (int i = 0; i < m; ++i) {
        // cout << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << endl;
        int p = a[i][1];
        int num = ++cnt[p];
        int oi = a[i][2];
        ans[oi] = p * 1000000LL + num;
    }
    for (int i = 0; i < m; ++i) {
        cout << setfill('0') << setw(12) << ans[i] << endl;
    }
    return 0;
}
