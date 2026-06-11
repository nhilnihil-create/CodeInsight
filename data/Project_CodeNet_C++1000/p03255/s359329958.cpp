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

ll solve (ll i, ll x) {
    if (i == 1) {
        return max((ll)0, 5 * x);
    } else {
        return max((ll)0, (2 * i + 1) * x);
    }
}

int main() {
    ll N, X;
    cin >> N >> X;
    ll x[N];
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i < N + 1; i++) {
        sum[i] = sum[i - 1] + x[i - 1];
    }
    ll ans = llmax;
    for (int k = 1; k <= N; k++) {
        ll tmp = 0;
        bool ok = true;
        for (int i = 1; i <= (N + k - 1) / k; i++) {
            ll xtop = N - 1 - (i - 1) * k;
            ll xbot = max(N - 1 - i * k + 1, (ll)0);
            ll tmpsum = sum[xtop + 1] - sum[xbot];
            ll tmpe = solve(i, tmpsum);
            if (tmpe == 0) {
                ok = false;
            }
            tmp += tmpe;
            if (tmpe < 0) {
                ok = false;
            }
        }
        ll ansnum = tmp + (N + k) * X;
        if (ansnum < 0) {
            ok = false;
        }
        //cout << ansnum << endl;
        if (ok && ansnum < ans) {
            ans = ansnum;
        }
    }
    cout << ans << endl;
}
