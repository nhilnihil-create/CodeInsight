#include <bits/stdc++.h>
using namespace std;
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep4(i, a, b, c) for (int i = int(a), i##__b = int(b), i##__c = int(c); i < i##__b; i += i##__c)
#define rep1(n) rep4(i, 0, n, 1)
#define rep2(i, n) rep4(i, 0, n, 1)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define REP(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep3(i, a, b) for (int i = int(b) - 1, i##__a = int(a); i >= i##__a; i--)
#define rrep1(n) rrep3(i, 0, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep4(i, a, b, c) for (int i = int(a + (b - a - 1) / c * c), i##__a = int(a), i##__c = int(c); i >= i##__a; i -= i##__c)
#define RREP(...) overload4(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define FOREACH(i, x) for (auto &i : x)
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define print(x) cout << x << endl;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 9;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vint = vector<int>;
using vvint = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using vbool = vector<bool>;
using vvbool = vector<vector<bool>>;
template <class T> using vv = vector<vector<T>>;
// clang-format off
template <class T> bool chmax(T &a, const T &b) {if (a < b) {a = b;return 1;}return 0;}
template <class T> bool chmin(T &a, const T &b) {if (b < a) {a = b;return 1;}return 0;}
// clang-format on


int main() {
    ll N;
    cin >> N;
    REP(h, 1, 3501) REP(n, 1, 3501) {
        ll bunbo = N * h * n, bunshi = 4 * h * n - N * (h + n);
        if (bunshi == 0) continue;
        if (bunbo % bunshi == 0) {
            ll w = bunbo / bunshi;
            if (w >= 0) {
                cout << h << " " << n << " " << bunbo / bunshi;
                return 0;
            }
        }
    }
    cerr << "end";
}