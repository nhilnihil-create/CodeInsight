#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int d, g;
    cin >> d >> g;
    vec p(d), c(d);
    rep(i, d) {
        cin >> p[i] >> c[i];
    }

    int res = INF;

    // 全完する問題を決め打ち　足りない分は点数が高いものから
    rep(f, 1 << d) {
        int cnt = 0;
        lint score = 0;

        rep(i, d) {
            int bit = (f >> i) & 1;
            if (bit) {
                cnt += p[i];
                lint base = (i+1) * 100;
                base *= p[i];
                score += base;
                score += c[i];
            }
        }

        if (score < g) {
            for (int i = d-1; i >= 0; --i) {
                int bit = (f >> i) & 1;
                if (bit) continue;
                rep(j, p[i]-1) {
                    cnt++;
                    score += (i+1) * 100;
                    if (score >= g) break;
                }
                if (score >= g) break;
            }
        }

        if (score < g) continue;
        res = min(res, cnt);
    }
    
    cout << res << endl;
    return 0;
}