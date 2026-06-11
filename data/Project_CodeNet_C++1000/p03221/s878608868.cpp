#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    // int n, m;
    // cin >> n >> m;
    // int p[m], y[m];
    // vector<set<pii>> s(n+1);
    // rep(i, m) {
    //     cin >> p[i] >> y[i];
    //     s[p[i]].insert({y[i], i});
    // }
    // vector<string> ans(m);
    // rep(i, n+1) {
    //     if (i > 0) {
    //         int cnt = 0;
    //         for (pii x : s[i]) {
    //             string t1 = to_string(i);
    //             while ((int)t1.size() < 6) {
    //                 t1 = '0' + t1;
    //             }
    //             string t2 = to_string(++cnt);
    //             while ((int)t2.size() < 6) {
    //                 t2 = '0' + t2;
    //             }
    //             ans[x.second] = t1 + t2;
    //         }
    //     }
    // }
    // rep(i, m) {
    //     cout << ans[i] << endl;
    // }
    int n, m;
    cin >> n >> m;
    map<int, pii> year;
    map<int, int> pref;
    rep(i, m) {
        int p, y;
        cin >> p >> y;
        year[y] = {p, i};
    }
    vector<string> ans(m);
    for (auto x : year) {
        string t1 = to_string(x.second.first);
        while ((int)t1.size() < 6) {
            t1 = '0' + t1;
        }
        string t2 = to_string(++pref[x.second.first]);
        while ((int)t2.size() < 6) {
            t2 = '0' + t2;
        }
        ans[x.second.second] = t1 + t2;
    }
    rep(i, m) {
        cout << ans[i] << endl;
    }
}