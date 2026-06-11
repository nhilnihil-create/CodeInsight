#include <bits/stdc++.h>
#define FASTIO
using namespace std;

using ll = long long;
using Vi = vector<int>;
using Vl = vector<ll>;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;

constexpr int I_INF = numeric_limits<int>::max();
constexpr ll L_INF = numeric_limits<ll>::max();

//==================================

int main() {
#ifdef FASTIO
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(false);
#endif
#ifdef FILEINPUT
    ifstream ifs("./in_out/input.txt");
    cin.rdbuf(ifs.rdbuf());
#endif

    int N, K;
    cin >> N >> K;
    vector<Pii> ps(N);
    for (int i = 0; i < N; i++) {
        cin >> ps[i].first >> ps[i].second;
    }

    Vi xs(N), ys(N);
    for (int i = 0; i < N; i++) {
        xs[i] = ps[i].first;
        ys[i] = ps[i].second;
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    sort(ys.begin(), ys.end());
    ys.erase(unique(ys.begin(), ys.end()), ys.end());

    int num_x = (int)xs.size();
    int num_y = (int)ys.size();

    unordered_map<int, int> idx_x, idx_y;
    for (int i = 0; i < num_x; i++) {
        idx_x[xs[i]] = i;
    }
    for (int i = 0; i < num_y; i++) {
        idx_y[ys[i]] = i;
    }

    vector<Vi> csum(num_x + 1, Vi(num_y + 1));
    for (int i = 0; i < N; i++) {
        int ix = idx_x[ps[i].first];
        int iy = idx_y[ps[i].second];
        csum[ix + 1][iy + 1] = 1;
    }
    for (int i = 0; i < num_x; i++) {
        for (int j = 0; j < num_y; j++) {
            csum[i + 1][j + 1] += csum[i + 1][j] + csum[i][j + 1] - csum[i][j];
        }
    }

    ll ans = L_INF;
    for (int i = 0; i <= num_x; i++) {
        for (int j = 0; j <= num_y; j++) {
            for (int x = i + 1; x <= num_x; x++) {
                for (int y = j + 1; y <= num_y; y++) {
                    int cnt = csum[x][y] - csum[x][j] - csum[i][y] + csum[i][j];
                    if (cnt >= K) {
                        ll s = (ll)(xs[x - 1] - xs[i]) * (ll)(ys[y - 1] - ys[j]);
                        ans = min(ans, s);
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}