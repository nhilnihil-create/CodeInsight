#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

// cの小さい順に並べる
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    return a.first.second < b.first.second;
}

int main() {

    int n, C; cin >> n >> C;

    vector<pair<pair<int, int>, int>> tv(n);
    for (int i = 0; i < n; ++i) {
        int s, t, c; cin >> s >> t >> c;
        tv[i] = make_pair(make_pair(s, t), c);
    }

    // 区間スケジューリングの考え方でソート
    sort(tv.begin(), tv.end(), compare);

    // 終わり時間、チャンネル
    vector<pair<int, int>> rokuga;
    for (int i = 0; i < n; ++i) {
        auto p = tv[i];

        bool ok = false;
        for (auto &r : rokuga) {
            // チャンネルが同じ かつ 時間もOK
            if (p.second == r.second && p.first.first >= r.first) {
                r.first = p.first.second;
                ok = true;
                break;
            }

            // チャンネルが違う かつ 時間OK
            if (p.second != r.second && p.first.first > r.first) {
                r.second = p.second;
                r.first = p.first.second;
                ok = true;
                break;
            }
        }

        if (!ok) {
            rokuga.push_back(make_pair(p.first.second, p.second));
        }

        sort(rokuga.rbegin(), rokuga.rend());
    }

    cout << rokuga.size() << endl;
}