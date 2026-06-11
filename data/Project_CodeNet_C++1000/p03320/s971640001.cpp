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

int ketasum(ll n) {
    int ans = 0;
    while (true) {
        ans += n % 10;
        n /= 10;
        if (n == 0) {
            break;
        }
    }
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    // double p[100001];
    // REP(i, 1, 100001) {
    //     ll num = ketasum(i);
    //     p[i] = (double)i / (double)num;
    // }
    // REP(i, 1, 100001) {
    //     bool ok = true;
    //     REP(j, i + 1, 100001) {
    //         if (p[i] > p[j]) {
    //             ok = false;
    //         }
    //     }
    //     if (ok) {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
    vector<ll> vec;
    REP(i, 1, 1000) {
        ll tmp = i;
        REP(j, 0, 15) {
            vec.push_back(tmp);
            tmp = tmp * 10 + 9;
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    ll len = vec.size();
    vector<double> val(len);
    REP(i, 0, len) {
        ll keta = ketasum(vec[i]);
        val[i] = (double)(vec[i]) / (double)(keta);
    }
    vector<ll> ans;
    REP(i, 0, len) {
        bool ok = true;
        REP(j, i + 1, len) {
            if (val[i] > val[j]) {
                ok = false;
            }
        }
        if (ok) {
            ans.push_back(vec[i]);
        }
    }
    REP(i, 0, K) {
        cout << ans[i] << endl;
    }
}
