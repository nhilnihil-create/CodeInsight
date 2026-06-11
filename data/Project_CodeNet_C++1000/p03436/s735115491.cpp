
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

template <typename T>
void quit(T a)
{
    cout << a << endl;
    exit(0);
}

using Graph = vector<vector<int>>;
using P = pair<int, int>;
using P1 = pair<int, pair<int, int>>; // クラスカル法とかで、{cost, {from, to}}的に使う。
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const double pi = acos(-1);

int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> s(h, vector<char>(w));
    int numdot = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> s[i][j];
            if (s[i][j] == '.')
            {
                numdot++;
            }
        }
    }
    vector<int> dx = {1, 0, 0, -1};
    vector<int> dy = {0, 1, -1, 0};
    vector<vector<int>> dist(h, vector<int>(w, -1));
    dist[0][0] = 0;
    queue<P> que;
    que.push({0, 0});
    while (!que.empty())
    {
        P p = que.front();
        que.pop();
        int x = p.fi;
        int y = p.se;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && dist[nx][ny] == -1 && s[nx][ny] == '.')
            {
                que.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    if(dist[h-1][w-1]==-1){
        quit(-1);
    }
    cout << numdot - dist[h - 1][w - 1] - 1 << endl;
    // debug_vec2(dist);
    // debug(numdot);

    return 0;
}
