#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define nl '\n'
#define f(i, n) for (int i = 0; i < n; ++i)
#define INF 1e9 + 5
using namespace std;
int solve() {
    int n;
    cin >> n;
    vector<int> d;
    int k = n;
    while (k) {
        d.push_back(k % 10);
        k /= 10;
    }

    int ans = INF;
    for (int i = 0; i < (int)d.size(); i++) {
        k = 100 * d[i] + 10 * d[i] + d[i];
        int l = 100 * (d[i] + 1) + 10 * (d[i] + 1) + d[i] + 1;
        if (k >= n) {
            ans = min({ans, k});
        }
        if (l >= n) {
            ans = min({ans, l});
        }
    }
    return ans;
}

bool okay(int a) {
    string s = to_string(a);
    for (int i = 0; i < (int)s.size() - 1; ++i) {
        if (s[i + 1] != s[i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // for (int i = 100; i <= 999; ++i) {
    cout << (solve()) << nl;
    // }
    // solve();
}