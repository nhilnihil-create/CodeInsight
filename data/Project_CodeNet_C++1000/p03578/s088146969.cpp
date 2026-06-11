#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    sort(d.begin(), d.end());
    cin >> m;

    rep(i, m) {
        int t;
        cin >> t;
        auto iter = lower_bound(d.begin(), d.end(), t);
        if (t != *iter) {
            cout << "NO" << endl;
            return 0;
        } else
            d.erase(iter);
    }

    cout << "YES" << endl;
    return 0;
}
