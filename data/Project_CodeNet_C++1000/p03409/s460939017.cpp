#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1000000007;
const int INF = 1000000000;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<pair<int, int>> red(N), blue(N);
    for (int i = 0; i < N; ++i) cin >> red[i].second >> red[i].first;
    for (int i = 0; i < N; ++i) cin >> blue[i].first >> blue[i].second;
    sort(red.begin(), red.end());
    sort(blue.begin(), blue.end());
    vector<bool> used_red(N, false);
    int ans = 0;
    for (auto bp : blue) {
        int bx = bp.first;
        int by = bp.second;
        for (int i = N - 1; i >= 0; --i) {
            if (used_red[i]) continue;
            int rx = red[i].second;
            int ry = red[i].first;
            if (rx < bx && ry < by) {
                ++ans;
                used_red[i] = true;
                break;
            }
        }
    }
    cout << ans << endl;
}
