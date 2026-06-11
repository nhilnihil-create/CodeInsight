#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define LCM(a, b) (a) / __gcd((a), (b)) * (b)
#define CEIL(a, b) (a)/(b)+(((a)%(b))?1:0)
#define ln '\n'

using namespace std;
using LL = long long;
using ldouble = long double;
using P = pair<int, int>;
using LP = pair<LL, LL>;

static const int INF = INT_MAX;
static const LL LINF = LLONG_MAX;
static const int MIN = INT_MIN;
static const LL LMIN = LLONG_MIN;
static const int MOD = 1e9 + 7;
static const int SIZE = 200005;

const int dx[] = {0, -1, 1, 0};
const int dy[] = {-1, 0, 0, 1};

vector<LL> Div(LL n) {
    vector<LL> ret;
    for(LL i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            ret.pb(i);
            if(i * i != n) ret.pb(n / i);
        }
    }
    sort(all(ret));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    int mp[505][505];
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            cin >> mp[i][j];
        }
    }

    vector<pair<P, P>> res;
    for(int i = 1; i <= H; ++i) {
        for(int j = 1; j <= W; ++j) {
            if(mp[i][j] % 2 == 0) continue;
            if(i == H && j == W) continue;
            if(i == H) {
                res.pb(MP(MP(i, j), MP(i, j + 1)));
                mp[i][j + 1]++;
            } else if(j == W) {
                res.pb(MP(MP(i, j), MP(i + 1, j)));
                mp[i + 1][j]++;
            } else {
                if(mp[i][j + 1] % 2 == 1) {
                    res.pb(MP(MP(i, j), MP(i, j + 1)));
                    mp[i][j + 1]++;
                } else {
                    res.pb(MP(MP(i, j), MP(i + 1, j)));
                    mp[i + 1][j]++;
                }
            }
        }
    }

    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i) {
        cout << res[i].F.F << " " << res[i].F.S << " " << res[i].S.F << " " << res[i].S.S << endl;
    }

    return 0;
}

