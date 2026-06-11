#include <bits/stdc++.h>

using namespace std;
#define int long long
#define x first
#define y second

#define vert int v, int tl, int tr
#define tm ((tl + tr) >> 1)
#define left (v << 1), tl, tm
#define right (v << 1) + 1, tm, tr

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;

vector<int> byh[200009];

signed main() {
    ios :: sync_with_stdio(0);
    cin.tie(0);

    int h, w, n;
    cin >> h >> w >> n;

    vector<pii> a(n);
    int y = 1;

    for (int i = 0; i < n; i ++) {
        cin >> a[i].x >> a[i].y;
        byh[a[i].x].push_back(a[i].y);
    }

    for (int i = 1; i <= h; i ++) {
        sort(byh[i].begin(), byh[i].end());
    }

    for (int i = 1; i <= w; i ++) {
        byh[h + 1].push_back(i);
    }

    for (int i = 1; i <= h; i ++) {
        auto ret = upper_bound(byh[i + 1].begin(), byh[i + 1].end(), y) - byh[i + 1].begin();
        if (ret > 0) {
            cout << i;
            return 0;
        }

        if (ret == byh[i + 1].size() || byh[i + 1][ret] != y + 1) {
            y++;
        }
    }

    return 0;
}
