//#define LOCAL
//#define BUG
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;

#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define pb push_back
#define ins insert
#define rsz resize
#define lb lower_bound
#define ub upper_bound
#define fore(i, a, b) for (int i = (a), _b = (b); i < _b; ++i)
#define fort(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define ford(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " /";
    __f(comma + 1, args...);
}
#endif

template <class T> bool mini(T& a, T b) { return a > b ? (a = b, 1) : 0; }
template <class T> bool maxi(T& a, T b) { return a < b ? (a = b, 1) : 0; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<vii> vvii;

const ll INF = (ll)1e9 + 7;
const int N = 3e3 + 3;

int n;
char s[N];
ll f[N][N];

int main() {
#ifdef LOCAL
    freopen("CP.inp", "r", stdin);
//    freopen("CP.out", "w", stdout);
#endif // LOCAL
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    fort(i, 1, n) f[1][i] = i;
    fort(i, 2, n) {
        if (s[i - 1] == '<') {
            fort(j, 1, i) f[i][j] = (((f[i][j - 1] + f[i - 1][j - 1] - f[i - 1][0]) % INF) + INF) % INF;
        } else {
            fort(j, 1, i) f[i][j] = (((f[i][j - 1] + f[i - 1][i - 1] - f[i - 1][j - 1]) % INF) + INF) % INF;
        }
    }
    cout << f[n][n] << '\n';
    return 0;
}
