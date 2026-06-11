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
#define REP(i, x, y) for(ll i = x; i < y; i++)
#define PER(i, x, y) for(ll i = x; i > y; i--)
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
double eps = 1e-11;

int main() {
    ll H, W, N;
    cin >> H >> W >> N;
    ll X[N], Y[N];
    REP(i, 0, N) {
        cin >> X[i] >> Y[i];
    }
    plglg pt[N + 1];
    REP(i, 0, N) {
        pt[i] = plglg(Y[i] - 1, X[i] - 1);
    }
    pt[N] = plglg(inf, inf);
    sort(pt, pt + N);
    ll num[W];
    fill(num, num + W, H - 1);
    ll h = 0;
    num[0] = 0;
    REP(i, 1, W) {
        h++;
        if (h >= H) {
            num[i] = -1;
            continue;
        }
        ll id = lower_bound(pt, pt + N + 1, plglg(i, h)) - pt;
        while (1) {
            if (pt[id].first != i || pt[id].second != h) {
                num[i] = h;
                break;
            } else {
                h++;
                id++;
                if (h >= H) {
                    num[i] = -1;
                    break;
                }
            }
        }
    }
    // REP(i, 0, W) {
    //     cout << num[i] << " ";
    // }
    // cout << endl;
    ll ans = H;
    REP(i, 0, N) {
        plglg p = pt[i];
        ll x = p.first;
        ll y = p.second;
        if (y > num[x] && num[x] != -1) {
            ans = min(ans, y);
        }
    }
    cout << ans << endl;
}
