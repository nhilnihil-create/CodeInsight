#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll a, ll b) {
    ll res = 2 * (a - 1) + (a + 1 < b);
    ll ok = a, ng = b - 1;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        ll hoge = (a * b + mid - 1) / mid - 1;
        if (mid == hoge) {
            res--;
        }
        if (mid > hoge) ng = mid;
        else ok = mid;
    }
    res += (ok - a) * 2;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        ll a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        cout << solve(a, b) << endl;
    }
    return 0;
}