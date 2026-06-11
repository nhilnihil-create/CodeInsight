#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <iomanip>
#include <numeric>
#include <tuple>
#include <bitset>
#include <complex>
#include <unistd.h>
#include <cassert>
#include <cctype>
#include <random>
#include <time.h>
#define _USE_MATH_DEFINES
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef pair<double, ll> pdlg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
typedef tuple<double, double, double> tddd;
typedef complex<double> xy_t;
typedef vector<ll> vll;
typedef vector< vector<ll> > matrix;
#define REP(i, x, y) for(ll i = (ll)x; i < (ll)y; i++)
#define DREP(i, x, y, d) for(ll i = (ll)x; i < (ll)y; i += (ll)d)
#define PER(i, x, y) for(ll i = (ll)x; i > (ll)y; i--)
#define DPER(i, x, y, d) for(ll i = (ll)x; i > (ll)y; i -= (ll)d)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
double pi = 3.141592653589793;
ll mod = 1000000007;
int intmax = 2147483647;
int intmin = -2147483648;
ll llmax = 9223372036854775807;
ll llmin = -9223372036854775807;
int iinf = intmax / 8;
ll inf = llmax / 8;
double eps = 1e-12;

ll dp[1010][20010];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    tlglglg t[N];
    REP(i, 0, N) {
        ll w, s, v;
        cin >> w >> s >> v;
        t[i] = tlglglg(w, s, v);
    }
    sort(t, t + N, [] (tlglglg x, tlglglg y) -> bool {
            return get<0>(x) + get<1>(x) < get<0>(y) + get<1>(y);
        });
    REP(i, 0, 1010) {
        fill(dp[i], dp[i] + 20010, -1);
    }
    dp[0][0] = 0;
    REP(i, 0, N) {
        tlglglg now = t[i];
        ll w = get<0>(now);
        ll s = get<1>(now);
        ll v = get<2>(now);
        REP(j, 0, 20010) {
            if (dp[i][j] != -1) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                if (j <= s && j + w < 20010) {
                    dp[i + 1][j + w] = max(dp[i + 1][j + w], dp[i][j] + v);
                }
            }
        }
    }
    ll ans = 0;
    REP(i, 0, 20010) {
        ans = max(ans, dp[N][i]);
    }
    cout << ans << endl;
}
