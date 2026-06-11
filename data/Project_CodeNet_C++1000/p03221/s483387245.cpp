#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    int n, m;
    cin >> n >> m;
    int p[m], y[m];
    vector<set<pii>> s(n + 1);
    rep(i, m) {
        cin >> p[i] >> y[i];
        s[p[i]].insert({y[i], i});
    }
    vector<string> ans(m);
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (pii x : s[i]) {
            string t1 = to_string(i);
            while ((int)t1.size() < 6) {
                t1 = '0' + t1;
            }
            string t2 = to_string(++cnt);
            while ((int)t2.size() < 6) {
                t2 = '0' + t2;
            }
            ans[x.second] = t1 + t2;
        }
    }
    rep(i, m) {
        cout << ans[i] << endl;
    }
}