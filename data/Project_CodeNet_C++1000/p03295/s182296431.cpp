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
    int n, m; cin >> n >> m;
    V<P> v(m);
    rep(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        v[i].first = b;
        v[i].second = a;
    }
    sort(all(v));
    int ans = 0;
    int r = -1;
    rep(i, m) {
        if (r <= v[i].second) {
            r = v[i].first;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}