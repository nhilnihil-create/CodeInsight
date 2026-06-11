#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <iomanip>
#include <set>
#include <ctime>
#include <tuple>
#include <bitset>
#include <assert.h>
#include <deque>
#include <functional>
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

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double pi = acos(-1);

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

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, INF);
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i + 1 <= n)
        {
            dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        }
        int tmp = 6;
        for (int j = 0; j <= n; j++)
        {
            if (i + tmp <= n)
            {
                dp[i + tmp] = min(dp[i + tmp], dp[i] + 1);
            }
            else
            {
                break;
            }
            tmp *= 6;
        }
        tmp = 9;
        for (int j = 0; j <= n; j++)
        {
            if (i + tmp <= n)
            {
                dp[i + tmp] = min(dp[i + tmp], dp[i] + 1);
            }
            else
            {
                break;
            }
            tmp *= 9;
        }

        // debug_vec(dp);
    }
    cout << dp[n] << endl;
    // debug_vec(dp);

    return 0;
}
