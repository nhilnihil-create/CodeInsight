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

int col[35][35];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, c;
    cin >> n >> c;
    for(int i = 1; i <= c; ++i) {
        for(int j = 1; j <= c; ++j) {
            cin >> col[i][j];

        }
    }

    int grid[505][505];
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            cin >> grid[i][j];

        }
    }
    vector<int> mod[3];
    for(int i = 0; i < 3; ++i) {
        for(int j = 1; j <= c; ++j) {
            int sum = 0;
            for(int k = 1; k <= n; ++k) {
                for(int l = 1; l <= n; ++l) {
                    if((k + l) % 3 == i) sum += col[grid[k][l]][j];

                }
            }
            mod[i].pb(sum);
        }
    }

    int res = INF;
    for(int i = 0; i < c; ++i) {
        for(int j = 0; j < c; ++j) {
            for(int k = 0; k < c; ++k) {
                if(i == j || j == k || i == k) continue;
                res = min(res, mod[0][i] + mod[1][j] + mod[2][k]);

            }
        }
    }
    cout << res << endl;
    return 0;
}
