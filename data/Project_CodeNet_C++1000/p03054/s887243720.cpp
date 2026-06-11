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
    int H, W, N;
    int sr, sc;
    string S, T;
    void input() {
        cin >> H >> W >> N;
        cin >> sr >> sc >> S >> T;
        --sr;
        --sc;
    }
    void output() {
        string d = "LURDLU";
        int dr[] = {0, -1, 0, 1, 0, -1};
        int dc[] = {-1, 0, 1, 0, -1, 0};
        REP(i, 4) {
            int r = sr, c = sc;
            REP(j, N) {
                if (S[j] == d[i]) {
                    r += dr[i];
                    c += dc[i];
                    if (r < 0 || r >= H || c < 0 || c >= W) {
                        cout << "NO" << endl;
                        return;
                    }
                }
                if (T[j] == d[i + 2]) {
                    r += dr[i + 2];
                    c += dc[i + 2];
                    r = max(0, r);
                    r = min(H - 1, r);
                    c = max(0, c);
                    c = min(W - 1, c);
                }
            }
        }
        cout << "YES" << endl;
    }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
