#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for (int i = (start); i < (int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

ll H, W;
vector<vecll> c(10, vecll(10));

int main(void)
{
    cin >> H >> W;

    rep(y, 10) {
        rep(x, 10) {
            cin >> c[y][x];
        }
    }

    // 書き換え魔力最小値を求める
    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }

    ll ans = 0;
    rep(y, H) {
        rep(x, W) {
            ll a;
            cin >> a;
            if (a == -1) continue;
            
            ans += c[a][1];
        }
    }

    cout << ans << endl;

    return 0;
}