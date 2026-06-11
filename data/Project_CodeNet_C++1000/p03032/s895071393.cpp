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

const int N = 55;
int n, k, res;
int a[N];

int solve(int l, int r) {
    int b[N];
    int cnt = 0;
    int t = l + r;
    int remain = k - t;
    int sum = 0;
    for (int i = 0; i < l; ++i) {
        b[cnt++] = a[i];
        sum += a[i];
    }
    for (int i = 0; i < r; ++i) {
        b[cnt++] = a[n - 1 - i];
        sum += a[n - 1 - i];
    }
    sort(b, b + t);
    int ri = 0;
    while (remain && ri < t && b[ri] < 0) {
        sum -= b[ri++];
        --remain;
    }
    // cout << l << ' ' << r << ' ' << sum << endl;
    return sum;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int l = 0; l <= min(n, k); ++l) {
        int rmax = min(n - l, k - l);
        for (int r = 0; r <= rmax; ++r) {
            res = max(res, solve(l, r));
        }
    }
    cout << res << endl;
    return 0;
}
