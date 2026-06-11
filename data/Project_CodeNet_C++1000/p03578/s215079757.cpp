#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define endl "\n"
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    vector<int> d(n);
    rep(i, 0, n) cin >> d[i];
    cin >> m;
    vector<int> t(m);
    rep(i, 0, m) cin >> t[i];

    map<int, int> mpd, mpt;
    rep(i, 0, n) mpd[d[i]]++;
    rep(i, 0, m) mpt[t[i]]++;
    rep(i, 0, m) {
        int x = t[i];
        if (mpd[x] < mpt[x]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
