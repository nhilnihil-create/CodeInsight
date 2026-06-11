#include <bits/stdc++.h>

using namespace std;

#define vt          vector
#define sz(x)       int((x).size())
#define all(x)      (x).begin(), (x).end()
#define rall(x)     (x).rbegin(), (x).rend()
#define fi          first
#define se          second

using ll = long long;
using pii = pair<int, int>;

void solve() {
    vt<int> a(9);
    for (int &x : a) cin >> x;

    vt<int> b(3);
    for (int i = 0; i < 3; i++) {
        int mn = *min_element(a.begin() + i * 3, a.begin() + i * 3 + 3);
        for (int j = 0; j < 3; j++) {
            if (!i) b[j] = a[j] - mn;
            else if (b[j] != a[i * 3 + j] - mn)
                return void(cout << "No");
        }
    }

    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int tcs = 1;
    for (int tc = 1; tc <= tcs; tc++) {
        // cout << "Case " << tc << ": ";
        solve();
    }
}

