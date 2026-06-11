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

ll N;
string S;
vector<char> red, blue;

ll dp[20][20];

ll dpmem(ll redrem, ll bluerem) {
    if (dp[redrem][bluerem] != -1) {
        return dp[redrem][bluerem];
    }
    if (redrem < 0 || bluerem < 0) {
        return 0;
    }
    if (redrem == 0 && bluerem == 0) {
        return 1;
    }
    ll tmp = 0;
    char c = S[N + redrem + bluerem - 1];
    if (redrem > 0 && red[red.size() - redrem] == c) {
        tmp += dpmem(redrem - 1, bluerem);
    }
    if (bluerem > 0 && blue[blue.size() - bluerem] == c) {
        tmp += dpmem(redrem, bluerem - 1);
    }
    return dp[redrem][bluerem] = tmp;
}

int main() {
    cin >> N;
    cin >> S;
    ll ans = 0;
    REP(i, 0, (1 << N)) {
        red.clear();
        blue.clear();
        REP(j, 0, N) {
            if (i & (1 << j)) {
                red.push_back(S[j]);
            } else {
                blue.push_back(S[j]);
            }
        }
        REP(i, 0, 20) {
            fill(dp[i], dp[i] + 20, -1);
        }
        ll redlen = red.size();
        ll bluelen = blue.size();
        ans += dpmem(redlen, bluelen);
    }
    cout << ans << endl;
}
