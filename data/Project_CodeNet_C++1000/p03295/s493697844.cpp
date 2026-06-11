#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, m;
    cin >> n >> m;

    vector<P> v;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }

    sort(v.begin(), v.end());

    // rep(i, m) {
    //     cout << "i: " << i << " f: " << v[i].first << " s: " << v[i].second << endl; 
    // }
    // cout << endl;

    int ans = 0;
    int t = 1;
    rep(i, m) {
        if (t <= v[i].second) {
            // cout << "i: " << i << " " << v[i].first << " x " <<v[i].second << endl;
            ans++;
            t = v[i].first;
        }
    }

    cout << ans << endl;

    return 0;
}