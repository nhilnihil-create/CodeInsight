#include"bits/stdc++.h"
using namespace std;
#define REP(k,m,n) for(int (k)=(m);(k)<(n);(k)++)
#define rep(i,n) REP((i),0,(n))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using tp3 = tuple<int, int, int>;
using Mat = vector<vector<ll>>;
constexpr int INF = 1 << 28;
constexpr ll INFL = 1ll << 60;
constexpr int dh[4] = { 0,1,0,-1 };
constexpr int dw[4] = { -1,0,1,0 };
bool isin(const int H, const int W, const int h, const int w) {
    return 0 <= h && h < H && 0 <= w && w < W;
}
template<typename T>
T chmin(T& l, T r) {
    return l = min(l, r);
}
template<typename T>
T chmax(T& l, T r) {
    return l = max(l, r);
}
// ============ template finished ============

int main()
{
    int H, W, N;
    cin >> H >> W >> N;
    map<int, set<int>> blocks;
    rep(i, N) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        blocks[X].insert(Y);
    }
    rep(w, W + 1) blocks[H].insert(w);

    int nowx = 0;
    int maxy = 0;
    bool clump = false;
    while (true) {
        const auto& row = blocks[nowx + 1];
        auto itr = row.upper_bound(maxy);

        if (row.empty()) {
            // pass
        }
        else if (itr == row.begin()) {
            // pass
        }
        else {
            break;
        }

        if (row.find(maxy + 1) == row.end())maxy++;
        nowx++;
    }
    cout << nowx + 1 << endl;
    return 0;
}
