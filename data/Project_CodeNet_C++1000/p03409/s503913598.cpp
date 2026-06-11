#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    int n; cin >> n;

    vector<pair<pair<int, int>, bool>> r(n);
    vector<pair<int, int>> b(n);

    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        r[i] = make_pair(make_pair(x, y), false);
    }

    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        b[i] = make_pair(x, y);
    }

    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        //bを一つずつ見ていく
        //rは全て確認
        int mx_y = -1;
        int idx = -1;
        for (int j = 0; j < n; ++j) {
            if (r[j].second) continue;

            if (r[j].first.first < b[i].first && r[j].first.second < b[i].second) {
                if (r[j].first.second > mx_y) {
                    idx = j;
                    mx_y = r[j].first.second;
                }
            }
        }

        if (idx != -1) {
            r[idx].second = true;
            ++ans;
        }
    }

    cout << ans << endl;
}