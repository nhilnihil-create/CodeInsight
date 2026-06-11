#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);
    
    int N, M; cin >> N >> M;
    vector<int> p(N);
    rep(i, N) {
        int t; cin >> t;
        t--;
        p[i] = t;
    }

    vector<vector<int>> e(N);

    rep(i, M) {
        int x, y; cin >> x >> y;
        x--; y--;
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }

    vector<int> achi(N);

    int ans = 0;
    rep(i, N) {
        if (achi[i]) continue;

        achi[i] = 1;

        vector<int> nb_sets;
        vector<int> sets;
        nb_sets.emplace_back(p[i]);
        sets.emplace_back(i);

        stack<int> st;
        st.push(i);

        while (!st.empty()) {
            int ni = st.top(); st.pop();
            for (auto ne: e[ni]) {
                if (achi[ne]) continue;
                achi[ne] = 1;
                nb_sets.emplace_back(p[ne]);
                sets.emplace_back(ne);
                st.push(ne);
            }
        }

        sort(nb_sets.begin(), nb_sets.end());
        sort(sets.begin(), sets.end());

        int ls = sets.size();
        int a = 0, b = 0;
        while (a < ls && b < ls) {
            if (nb_sets[a] == sets[b]) {
                ans += 1;
                a += 1;
                b += 1;
            } else if (nb_sets[a] < sets[b]) {
                a += 1;
            } else {
                b += 1;
            }
        }
    }
    cout << ans << endl;

    return 0;
}