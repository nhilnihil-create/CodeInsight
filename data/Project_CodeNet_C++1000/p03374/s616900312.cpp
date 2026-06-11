#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5 + 5;

ll x[MAXN + 1];
int v[MAXN + 1];

ll val[MAXN + 1];
ll mxl[MAXN + 1], mxr[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i;
    ll c;
    ios::sync_with_stdio(false);
    cin >> n >> c;
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> v[i];
    }
    x[n + 1] = c;
    for(i = n; i >= 1; i--) {
        val[i] = val[i + 1] + (c - x[i + 1]) + v[i] - (c - x[i]);
        mxr[i] = max(val[i], mxr[i + 1]);
    }
    for(i = 1; i <= n; i++) {
        val[i] = val[i - 1] + x[i - 1] + v[i] - x[i];
        mxl[i] = max(val[i], mxl[i - 1]);
    }
    ll ans = 0;
    ll cur = 0;
    for(i = n; i >= 1; i--) {
        cur += v[i];
        ans = max(ans, cur - (c - x[i]));
    }
    cur = 0;
    for(i = 1; i <= n; i++) {
        cur += v[i];
        ans = max(ans, cur - x[i]);
        ans = max(ans, cur - 2 * x[i] + mxr[i + 1]);
    }
    cur = 0;
    for(i = n; i >= 1; i--) {
        cur += v[i];
        ans = max(ans, cur - 2LL * (c - x[i]) + mxl[i - 1]);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}
