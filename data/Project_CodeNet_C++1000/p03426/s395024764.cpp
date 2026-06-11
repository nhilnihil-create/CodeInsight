#include<iostream>
#include<vector>
#include<string>
#include<map>
#define rep(i, start, end) for (int i = (int)start; i < (int)end; ++i)
#define rrep(i, start, end) for (int i = (int)start - 1; i >= (int)end; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
template<typename T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return 0;}
template<typename T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return 0;}

struct pos {
    int h, w;
    pos():h(-1), w(-1) {}
    pos(int h, int w):h(h), w(w) {}
    bool operator<(const pos& p) const {
        return h < p.h;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W, D;
    cin >> H >> W >> D;
    vector<vector<int>> A(H, vector<int>(W));
    rep(i, 0, H) rep(j, 0, W) {
        cin >> A[i][j];
    }
    int Q;
    cin >> Q;
    vector<int> L(Q), R(Q);
    rep(i, 0, Q) {
        cin >> L[i] >> R[i];
    }
    map<int, pos> pos_map;
    rep(i, 0, H) rep(j, 0, W) {
        pos_map[A[i][j]] = pos(i, j);
    }
    vector<ll> cumsum(H * W + 1, 0);
    rep(i, 1, D + 1) {
        for (int j = i + D; j <= H * W; j += D) {
            int h1 = pos_map[j - D].h;
            int w1 = pos_map[j - D].w;
            int h2 = pos_map[j].h;
            int w2 = pos_map[j].w;
            cumsum[j] = abs(h1 - h2) + abs(w1 - w2) + cumsum[j - D];
        }
    }
    rep(i, 0, Q) {
        cout << cumsum[R[i]] - cumsum[L[i]] << endl;
    }
    return 0;
}