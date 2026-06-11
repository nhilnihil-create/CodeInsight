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
const ll INF = 1001001001001001001;
const double pi = acos(-1);

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int, vector<int>, greater<int>> que;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        que.push(a);
    }
    vector<P> cb(m);
    for (int i = 0; i < m; i++)
    {
        int b, c;
        cin >> b >> c;
        cb.push_back({c, b});
    }
    sort(cb.begin(), cb.end());
    reverse(cb.begin(), cb.end());
    for (int i = 0; i < m; i++)
    {
        int x = cb[i].fi;
        int y = cb[i].se;
        while (y > 0)
        {
            if (que.top() < x)
            {
                que.pop();
                que.push(x);
                y--;
            }
            else
            {
                break;
            }
        }
    }
    ll ans = 0;
    while (!que.empty())
    {
        ll x = que.top();
        ans += x;
        que.pop();
    }
    cout << ans << endl;

    return 0;
}
