#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int magic (pair < int, int > a, pair < int, int > b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

signed main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int h, w, d;
    cin >> h >> w >> d;
    vector < pair < int, int > > pos(h * w + 1);
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            int a;
            cin >> a;
            pos[a] = make_pair(i, j);
        }
    }
    vector < vector < int > > pref(d);
    for (int i = 1; i <= d; ++i) {
        pref[i % d].push_back(0);
        pair < int, int > prv = pos[i];
        for (int j = i + d; j <= h * w; j += d) {
            pref[i % d].push_back(pref[i % d].back() + magic(prv, pos[j]));
            prv = pos[j];
        }
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << pref[r % d][r / d - int(r % d == 0)] - pref[r % d][l / d - int(l % d == 0)] << '\n';
    }
}
