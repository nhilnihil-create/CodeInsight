 #pragma GCC optimize("O3")
 #pragma GCC optimize("unroll-loops")
 #pragma GCC optimize("fast-math")
#include<bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define int long long
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

void accell() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}
int get(int x, vector<int>&a) {
    for (int i = 0; i < a.size(); ++i) {
        x = x / a[i] * a[i];
    }
    return x;
}

signed main() {
    accell();
    int n;
    cin >> n;
    vector<int>a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 1;
    int r = 1e18 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (get(m, a) >= 2)
            r = m;
        else
            l = m;
    }
    if (get(r, a) != 2) {
        cout << -1;
        return 0;
    }
    int ansl = r;
    l = 1;
    r = 1e18 + 1;
    while (r - l > 1) {
        int m = l + r >> 1;
        if (get(m, a) > 2)
            r = m;
        else
            l = m;
    }
    int ansr = l;
    cout << ansl << ' ' << ansr << endl;
    return 0;
}
