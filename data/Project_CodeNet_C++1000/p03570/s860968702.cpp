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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll len = s.size();
    ll dp[len];
    fill(dp, dp + len, inf);
    ll now = 0;
    map<ll, ll> mp;
    mp[0] = 1;
    REP(i, 0, len) {
        ll chnum = s[i] - 'a';
        now = now ^ ((ll)1 << chnum);
        // cout << now << endl;
        if (now == 0) {
            mp[now] = 1;
            dp[i] = 1;
        } else {
            REP(j, 0, 26) {
                ll p = now ^ ((ll)1 << j);
                if (p == 0) {
                    mp[now] = 1;
                    dp[i] = min(dp[i], (ll)1);
                } else {
                    if (mp.count(p) != 0) {
                        if (mp.count(now) != 0) {
                            mp[now] = min(mp[now], mp[p] + 1);
                        } else {
                            mp[now] = mp[p] + 1;
                        }
                        dp[i] = min(dp[i], mp[p] + 1);
                    }
                }
            }
        }
    }
    // REP(i, 0, len) {
    //     cout << dp[i] << endl;
    // }
    ll ans = dp[len - 1];
    cout << ans << endl;
}
