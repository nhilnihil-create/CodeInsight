#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> c(n), s(n), f(n);
    rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];

    rep(i, n) {
        ll now = 0;
        for (int j = i; j < n - 1; ++j) {
            if (now < s[j])
                now = s[j] + c[j];
            else {
                if (now % f[j] == 0)
                    now += c[j];
                else
                    now += (f[j] - now % f[j]) + c[j];
            }
        }
        cout << now << "\n";
    }

    return 0;
}