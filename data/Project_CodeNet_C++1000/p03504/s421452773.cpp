#include <bits/stdc++.h>
using namespace std;

using P= pair<int, int>;
const int MAX_T = 1e5 + 9;

int main() {
    int N, C;  cin >> N >> C;
    vector<vector<P>> v(C);
    for (int i = 0; i < N; ++i) {
        int s, t, c;
        cin >> s >> t >> c;  --c;
        v[c].push_back(P(s, t));
    }
    for (int c = 0; c < C; ++c) sort(v[c].begin(), v[c].end());
    // DUMP(v);

    vector<int> imos(MAX_T * 2);
    for (int c = 0; c < C; ++c) {
        int i = 0;
        if (i >= v[c].size()) continue;
        ++imos[v[c][i].first * 2 - 1];
        while (i < v[c].size()) {
            if (i + 1 < v[c].size() && v[c][i].second != v[c][i + 1].first) {
                --imos[v[c][i].second * 2 + 1];
                ++imos[v[c][i + 1].first * 2 - 1];
            }
            else if (i + 1 == v[c].size()) {
                --imos[v[c][i].second * 2 + 1];
            }
            ++i;
        }
    }

    int ans = 0;
    for (int i = 0; i < MAX_T * 2 - 1; ++i) {
        imos[i + 1] += imos[i];
        ans = max(ans, imos[i]);
    }
    cout << ans << endl;
}
