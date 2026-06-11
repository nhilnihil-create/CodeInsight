#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
public:
    Main() {
        int H, W;
        cin >> H >> W;
        vector<string> A(H);
        vector<vector<int>> cost(H, vector<int>(W, -1));
        queue<P> qu;
        int di[4] = {1, 0, -1, 0};
        int dj[4] = {0, 1, 0, -1};
        REP(i, H) {
            cin >> A[i];
            REP(j, W) {
                if (A[i][j] == '#') {
                    cost[i][j] = 0;
                    qu.emplace(i, j);
                }
            }
        }
        int res = 0;
        while (!qu.empty()) {
            int i, j;
            tie(i, j) = qu.front();
            qu.pop();
            res = cost[i][j];
            REP(k, 4) {
                int a = i + di[k];
                int b = j + dj[k];
                if (a >= 0 && a < H && b >= 0 && b < W) {
                    if (cost[a][b] == -1) {
                        cost[a][b] = cost[i][j] + 1;
                        qu.emplace(a, b);
                    }
                }
            }
        }
        cout << res << endl;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main ans;

    return 0;
}
