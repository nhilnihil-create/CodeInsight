#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int h, w, d; cin >> h >> w >> d;
    vector<pair<int, int>> p(h * w + 10);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int a; cin >> a;
            p[a] = make_pair(i + 1, j + 1);
        }
    }

    vector<int> s(h * w + 10, 0);
    for (int i = 1; i <= d; ++i) {
        int t = i;
        while (t + d < h * w + 10) {
            s[t + d] = s[t] + abs(p[t + d].first - p[t].first) + abs(p[t + d].second - p[t].second);
            t += d;
        }
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;

        if (l == r) {
            cout << 0 << endl;
        } else {
            cout << s[r] - s[l] << endl;
        }
    }
}