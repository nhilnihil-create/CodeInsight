#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using pil = pair<int, ll>;
using uint = unsigned int;
template <typename T>
using Graph = vector<vector<T>>;
const int MOD = 10007;
const ld PI = acosl(-1);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N;
    cin >> W >> H >> N;
    vector<pii> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
        v[i].first--, v[i].second--;
    }
    sort(v.begin(), v.end());

    int cnt = 0, idx = 0;
    for (int i = 0; i < W; ++i) {
        bool inc = true;
        while (idx < N && i + 1 >= v[idx].first) {
            if (v[idx].second <= cnt) {
                cout << i + 1 << endl;
                return 0;
            }
            if (v[idx].second == cnt + 1 || cnt + 1 >= H)
                inc = false;
            idx++;
        }
        if (inc)
            cnt++;
    }

    cout << W << endl;
    return 0;
}
