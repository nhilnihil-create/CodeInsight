#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr int Mod = 998244353;
constexpr int mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> constexpr bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> constexpr bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int H, W, N;
    cin >> H >> W >> N;
    vector<pair<int, int>> vec;
    vec.emplace_back(H, 0);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        if(x >= y) vec.emplace_back(x - 1, y - 1);
    }
    sort(ALL(vec));
    int giri = 0;
    for(auto p : vec) {
        if(p.first - p.second > giri) {
            cout << p.first << endl;
            return 0;
        }
        if(p.first - p.second == giri) giri++;
    }

    return 0;
}