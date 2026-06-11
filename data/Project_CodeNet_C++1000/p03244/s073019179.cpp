// 7/12
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];

    map<int, int> odds, evens;
    rep(i, n) {
        if (i&1) odds[v[i]]++;
        else evens[v[i]]++;
    }

    vector<P> odds2, evens2;
    for (auto p : odds) odds2.push_back({p.second, p.first});
    for (auto p : evens) evens2.push_back({p.second, p.first});

    sort(odds2.rbegin(), odds2.rend());
    sort(evens2.rbegin(), evens2.rend());

    // for (auto x : odds2) cout << "odds2: " << x.first << " " << x.second << endl;
    // for (auto x : evens2) cout << "evens2: " << x.first << " " << x.second << endl;

    int res = 0;
    if (n == 2) {
        if (v[0] == v[1]) cout << 1 << endl;
        else cout << 0 << endl;
    }
    if (n == 3) {
        if (v[0] == v[2]) cout << 0 << endl;
        else cout << 1 << endl;
    }
    if (odds2[0].second == evens2[0].second) {
        res = n;
        if (odds2[1].first >= evens2[1].first) {
            res -= odds2[1].first;
            res -= evens2[0].first;
        } else {
            res -= odds2[0].first;
            res -= evens2[1].first;
        }
    }
    else {
        // cout << "here?" << endl;
        res = n;
        res -= odds2[0].first;
        res -= evens2[0].first;
    }

    cout << res << endl;
}