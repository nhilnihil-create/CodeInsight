#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

// #define int ll
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FORE(i, s, n) for (int i = (s); i <= (int)(n); i++)
#define debug(x) cerr << #x << ": " << x << '\n'
#define hyphen() cerr << "--\n"

#define fst first
#define pb push_back

const int TIMES = 10;

const int MOD = (int)1e9 + 7;

signed main() {
    int N;
    cin >> N;

    vector<vector<int>> Fss(N, vector<int>(TIMES));
    REP(i, N) {
        REP(k, TIMES) {
            cin >> Fss.at(i).at(k);
        }
    }

    // 0があるから+1
    vector<vector<int>> Pss(N, vector<int>(TIMES+1));
    REP(i, N) {
        REP(k, TIMES + 1) {
            cin >> Pss.at(i).at(k);
        }
    }

    // 全探索でいきましょう
    int ans = numeric_limits<int>::min();

    FORE(state_bit, 1, 1023) {
        // debug(state_bit);

        int cost = 0;
        REP(shop, N) {
            // お姉ちゃんの店と店shopの両方が営業している時間帯の個数
            int cnt = 0;

            // 重なっている時間帯を調べたいよね
            REP(t, TIMES) {
                int joisino_open_at_t = (state_bit & (1 << t)) >> t;

                if (joisino_open_at_t == 1 && Fss.at(shop).at(t) == 1) {
                    cnt += 1;
                }
            }

            // コストを足す
            cost += Pss.at(shop).at(cnt);
        }

        if (cost > ans) {
            ans = cost;
        }
    }

    cout << ans << endl;
}
