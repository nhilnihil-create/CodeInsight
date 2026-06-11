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

ll b[100010];
plglg c[100010];
ll bsum[100010];
ll mark[100010];

ll bit[1000010], n;

ll sum(int i) {
    ll s = 0;
    while (i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, ll x) {
    while (i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main() {
    ll N;
    cin >> N;
    ll a[N];
    REP(i, 0, N) {
        cin >> a[i];
    }
    if (N == 1) {
        cout << a[0] << endl;
        return 0;
    }
    ll hi = 1e9 + 1;
    ll lo = 0;
    while (hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        REP(i, 0, N) {
            if (a[i] >= mid) {
                b[i] = 1;
            } else {
                b[i] = -1;
            }
        }
        bsum[0] = b[0];
        REP(i, 1, N) {
            bsum[i] = bsum[i - 1] + b[i];
        }
        REP(i, 0, N) {
            c[i] = plglg(bsum[i], i);
        }
        sort(c, c + N);
        mark[c[0].second] = 1;
        ll tmp = 1;
        REP(i, 1, N) {
            if (c[i].first != c[i - 1].first) {
                tmp++;
            }
            mark[c[i].second] = tmp;
        }
        n = tmp;
        fill(bit, bit + n + 1, 0);
        ll inv = 0;
        REP(i, 0, N) {
            inv += i - sum(mark[i]);
            add(mark[i], 1);
        }

        ll num = N * (N - 1) / 2 - inv;
        //cout << mid << " " << num << endl;
        ll pl = lower_bound(c, c + N, plglg(0, 0)) - c;
        //cout << inv << " " << pl << endl;
        if (num + (N - pl) >= (N * (N + 1) / 2 + 1) / 2) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << endl;
}
