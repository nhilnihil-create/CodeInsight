#include <assert.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

#define fi first
#define se second
#define rep(i, n) for (ll i = 0; i < n; i++)
#define debugA cerr << "AAAAA" << endl
#define debug_ cerr << "-------------" << endl
#define debug(x) cerr << #x << ": " << x << endl
#define debug_vec(v)                   \
    cout << #v << endl;                \
    for (int i = 0; i < v.size(); i++) \
    {                                  \
        cout << v[i] << " ";           \
    }                                  \
    cout << endl;
#define debug_vec2(v)                         \
    cout << #v << endl;                       \
    for (int i = 0; i < v.size(); i++)        \
    {                                         \
        for (int j = 0; j < v[i].size(); j++) \
        {                                     \
            cout << v[i][j] << " ";           \
        }                                     \
        cout << endl;                         \
    }

template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
void quit(T a)
{
    cout << a << endl;
    exit(0);
}

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from,
                                      // to}}的に使う。
const ll LINF = 10010020030040056ll;
const int INF = 1001001001;
const double pi = acos(-1);

ll GCD(ll a, ll b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD(b, a % b);
}

vector<pair<ll, ll>> prime_factor(ll N)
{
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1)
        res.push_back({N, 1});
    return res;
}

void solve()
{
    int n;
    cin >> n;
    cout << n/3 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);

    solve();
    return 0;
}
