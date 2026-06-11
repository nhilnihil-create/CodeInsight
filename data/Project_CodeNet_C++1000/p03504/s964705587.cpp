#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
typedef long long ll;
#define ALL(v) v.begin(), v.end()
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define chmax(x, a) x = max(x, a)
#define chmin(x, a) x = min(x, a)

int main() {
    int N, C; cin >> N >> C;
    vector<int> imos(1e5+2);
    vector<vector<pair<int, int>>> vec(C);
    rep(i, N) {
        int s, t, c;
        cin >> s >> t >> c;
        vec[--c].push_back(make_pair(s, t));
    }
    rep(i, C) {
        bool flag = true;
        rep(j, vec[i].size()) {
            int s = vec[i][j].first, t = vec[i][j].second;
            if (flag) imos[s-1]++;
            if (j+1 >= vec[i].size()) {
                imos[t]--;
                continue;
            }
            if (vec[i][j+1].first == t) {
                flag = false;
                continue;
            }
            imos[t]--;
            flag = true;
        }
    }
    rep(i, imos.size()-1) imos[i+1] += imos[i];
    cout << min(C, vmax(imos)) << endl;
}
