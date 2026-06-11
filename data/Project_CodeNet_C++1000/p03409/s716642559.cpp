//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <x86intrin.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define chmin(x,y) x = min(x, y)
#define chmax(x,y) x = max(x, y)
#define V vector
vector<int> dx = {-1, 1,  0, 0, -1, -1,  1, 1};
vector<int> dy = { 0, 0, -1, 1, -1,  1, -1, 1};

int main () {
    int n; cin >> n;
    V<P> r(n), b(n);
    rep(i, n) {
        int a, b; cin >> a >> b;
        r[i].first = b; r[i].second = a;
    }
    rep(i, n) {
        int c, d; cin >> c >> d;
        b[i].first = c; b[i].second = d;
    }
    sort(allr(r));
    sort(all(b));
    
    V<bool> used_r(n, false);
    int ans = 0;
    rep(i, n) {
        int bx = b[i].first, by = b[i].second;
        rep(i, n) {
            int rx = r[i].second, ry = r[i].first;
            if (used_r[i]) continue;
            if (rx < bx && ry < by) {
                ans++;
                used_r[i] = true;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}