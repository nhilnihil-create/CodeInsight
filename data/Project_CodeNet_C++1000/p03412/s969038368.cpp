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
#define _USE_MATH_DEFINES
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> plglg;
typedef tuple<int, int, int> tiii;
typedef tuple<ll, ll, ll> tlglglg;
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
ll inf = llmax / 2;
double eps = 1e-11;

int main() {
    ll N;
    cin >> N;
    ll a[N], b[N];
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    ll ans = 0;
    REP (i, 0, 29) {
        ll acut[N];
        REP(j, 0, N) {
            acut[j] = a[j] % ((ll)1 << (i + 1));
        }
        ll bcut[N];
        REP(j, 0, N) {
            bcut[j] = b[j] % ((ll)1 << (i + 1));
        }
        sort(bcut, bcut + N);
        ll t = 1 << i;
        ll num = 0;
        REP (j, 0, N) {
            ll p = lower_bound(bcut, bcut + N, t - acut[j]) - bcut;
            ll q = lower_bound(bcut, bcut + N, 2 * t - acut[j]) - bcut;
            ll r = lower_bound(bcut, bcut + N, 3 * t - acut[j]) - bcut;
            ll s = lower_bound(bcut, bcut + N, 4 * t - acut[j]) - bcut;
            // cout << acut[j] << " " << t << " " << p << q << r << s << endl;
            // cout << (q - p) + (s - r) << endl;
            num = (num + ((q - p) + (s - r)) % 2) % 2;
        }
        ans += num * ((ll)1 << i);
    }
    cout << ans << endl;
}
