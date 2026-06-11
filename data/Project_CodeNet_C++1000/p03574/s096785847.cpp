#include <bits/stdc++.h>
using namespace std;
using ll         = long long;
constexpr ll MOD = 1000000007;
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define REP2(i, x, n) for (ll i = x; i < (n); i++)
const long long INF = numeric_limits<long long>::max();
void func(vector<string>& map, ll x, ll y) {
    if (x < 0) return;
    if (x >= map.size()) return;
    if (y < 0) return;
    if (y >= map[x].length()) return;

    auto& m = map[x][y];
    if (m != '#') {
        m++;
    }
}
int main() {
    ll H, W;
    cin >> H >> W;

    vector<string> map(H);
    for (ll i = 0; i < H; ++i) {
        cin >> map[i];
        for (ll j = 0; j < map[i].length(); ++j) {
            if (map[i][j] == '.') {
                map[i][j] = '0';
            }
        }
    }

    for (ll i = 0; i < H; ++i) {
        for (ll j = 0; j < map[i].length(); ++j) {
            if (map[i][j] == '#') {
                for (ll x = -1; x <= 1; ++x) {
                    for (ll y = -1; y <= 1; ++y) {
                        if (x == 0 && y == 0) continue;
                        func(map, i + x, j + y);
                    }
                }
            }
        }
    }

    for (ll i = 0; i < H; ++i) {
        cout << map[i] << endl;
    }
    return 0;
}