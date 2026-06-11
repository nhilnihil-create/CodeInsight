#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct tv {
    int s, t, c;
};

bool cmp(const tv t1, const tv t2) {
    return t1.t < t2.t;
}

int main() {
    int n, c; cin >> n >> c;
    vector<tv> infos(n);
    for (int i = 0; i < n; ++i) {
        int s, t, ci; cin >> s >> t >> ci;
        infos[i] = tv { s, t, ci };
    }
    sort(infos.begin(), infos.end(), cmp);
    vector<pair<int, int>> t_c;
    for (auto t : infos) {
        sort(t_c.begin(), t_c.end(), greater<>());
        int ts = t.s;
        int tt = t.t;
        int tc = t.c;
        bool possible = false;
        for (auto &ti : t_c) {
            if (ti.second == tc) {
                if (ti.first <= ts) {
                    possible = true;
                    ti.first = tt;
                    break;
                }
            } else {
                if (ti.first < ts) {
                    possible = true;
                    ti.first = tt;
                    ti.second = tc;
                    break;
                }
            }
        }
        if (!possible) {
            t_c.push_back({tt, tc});
        }
    }
    cout << t_c.size();
    return 0;
}
