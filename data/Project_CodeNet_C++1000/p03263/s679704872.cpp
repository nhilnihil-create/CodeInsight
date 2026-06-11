#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<pair<pii, pii>> res;
    rep(i, H) rep(j, W) cin >> A[i][j];
    for(int i = 0; i < H; i++) {
        if(i % 2 == 0) {
            for(int j = 0; j < W; j++) {
                if(j == W - 1) {
                    if(i + 1 == H)
                        continue;
                    if(A[i][j] % 2) {
                        res.pb(MP(MP(i + 1, j + 1), MP(i + 2, j + 1)));
                        A[i][j]--;
                        A[i + 1][j]++;
                    }
                } else {
                    if(A[i][j] % 2) {
                        res.pb(MP(MP(i + 1, j + 1), MP(i + 1, j + 2)));

                        A[i][j]--;
                        A[i][j + 1]++;
                    }
                }
            }
        } else {
            for(int j = W - 1; j >= 0; j--) {
                if(j == 0) {
                    if(i + 1 == H)
                        continue;
                    if(A[i][j] % 2) {
                        res.pb(MP(MP(i + 1, j + 1), MP(i + 2, j + 1)));

                        A[i][j]--;
                        A[i + 1][j]++;
                    }
                } else {

                    if(A[i][j] % 2) {
                        res.pb(MP(MP(i + 1, j + 1), MP(i + 1, j)));
                        A[i][j]--;
                        A[i][j - 1]++;
                    }
                }
            }
        }
    }
    cout << res.size() << endl;
    rep(i, res.size()) {
        cout << res[i].first.first << ' ' << res[i].first.second << ' '
             << res[i].second.first << ' ' << res[i].second.second << endl;
    }
    return 0;
}