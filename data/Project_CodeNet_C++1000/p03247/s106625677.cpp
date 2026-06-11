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

int main() {
    ll N;
    cin >> N;
    ll X[N], Y[N];
    int mark = -1;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
        if (i == 0) {
            mark = (abs(X[i]) + abs(Y[i])) % 2;
        } else {
            if (mark != (abs(X[i]) + abs(Y[i])) % 2) {
                ok = false;
            }
        }
    }
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    if (mark == 0) {
        for (int i = 0; i < N; i++) {
            Y[i]--;
        }
    }
    ll u[N], v[N];
    for(int i = 0; i < N; i++) {
        u[i] = X[i] + Y[i];
        v[i] = X[i] - Y[i];
    }
    ll m = 31;
    if (mark == 0) {
        m++;
    }
    ll d[m];
    for (int i = 0; i < 31; i++) {
        d[i] = 1 << i;
    }
    if (mark == 0) {
        d[31] = 1;
    }
    string ans[N];
    fill(ans, ans + N, "");
    for (int i = 0; i < N; i++) {
        ll unum = (u[i] + (1 << 31) - 1) / 2;
        ll vnum = (v[i] + (1 << 31) - 1) / 2;
        for (int j = 0; j < 31; j++) {
            bool uok, vok;
            if ((unum & (1 << j)) > 0) {
                uok = true;
            } else {
                uok = false;
            }
            if ((vnum & (1 << j)) > 0) {
                vok = true;
            } else {
                vok = false;
            }
            if (uok) {
                if (vok) {
                    ans[i].push_back('R');
                } else {
                    ans[i].push_back('U');
                }
            } else {
                if (vok) {
                    ans[i].push_back('D');
                } else {
                    ans[i].push_back('L');
                }
            }
        }
        if (mark == 0) {
            ans[i].push_back('U');
        }
    }
    cout << m << endl;
    for (int i = 0; i < m; i++) {
        cout << d[i];
        if (i != m - 1) {
            cout << " ";
        } else {
            cout << endl;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}
