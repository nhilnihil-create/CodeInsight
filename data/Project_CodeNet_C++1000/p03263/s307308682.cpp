#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int dh[4] = {-1, 0, 1, 0},
    dw[4] = {0, 1, 0, -1};

int main() {
    cout << fixed << setprecision(10);
    
    int H, W; cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    rep(i, H) rep(j, W) cin >> a[i][j];

    stack<P> stk;
    stk.emplace(make_pair(0, 0));
    vector<vector<int>> thr(H, vector<int>(W));
    thr[0][0] = 1;
    int has_odd = 0;
    vector<P> troute;
    if (a[0][0] % 2 == 1) {
        has_odd = 1;
        troute.emplace_back(make_pair(0, 0));
    }

    vector<vector<P>> route;
    int n = 0;

    while (!stk.empty()) {
        auto p = stk.top(); stk.pop();
        int ch = p.first, cw = p.second;
        rep(i, 4) {
            int nh = ch + dh[i], nw = cw + dw[i];
            if (nh >= 0 && nw >= 0 && nh < H && nw < W && thr[nh][nw] == 0) {
                stk.emplace(make_pair(nh, nw));
                thr[nh][nw] = 1;
                if (has_odd) {
                    troute.emplace_back(make_pair(nh, nw));
                    if (a[nh][nw] % 2 == 1) {
                        route.emplace_back(troute);
                        n += troute.size() - 1;
                        troute.clear();
                        has_odd = 0;
                    }
                } else {
                    if (a[nh][nw] % 2 == 1) {
                        troute.emplace_back(make_pair(nh, nw));
                        has_odd = 1;
                    }
                }
                break;
            }
        }
    }

    cout << n << endl;
    rep(i, route.size()) {
        rep(j, route[i].size()-1) {
            cout << route[i][j].first + 1 << " " << route[i][j].second + 1 << " ";
            cout << route[i][j+1].first + 1 << " " << route[i][j+1].second + 1 << endl;
        }
    }


    return 0;
}