#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (ll i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (ll i = n; i >= 0; i--)
#define Pool(i, m, n) for (ll i = n; i >= m; i--)
#define mod 1000000007ll
//#define mod 998244353ll
#define flagcount __builtin_popcount
#define flag(x) (1ll << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1ll << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}
template <typename T>
bool primejudge(T n)
{
    if (n < 2)
        return false;
    else if (n == 2)
        return true;
    else if (n % 2 == 0)
        return false;
    double sqrtn = sqrt(n);
    for (T i = 3; i < sqrtn + 1; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
        i++;
    }
    return true;
}
template <typename T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
template <typename T>
bool chmin(T &a, const T &b)
{
    if (a > b)
    {
        a = b; // aをbで更新
        return true;
    }
    return false;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));

vector<long long> topo_sort(const vector<vector<long long>> &G)
{ // bfs
    vector<long long> ans;
    long long n = (long long)G.size();
    vector<long long> ind(n); // ind[i]: 頂点iに入る辺の数(次数)
    for (long long i = 0; i < n; i++)
    { // 次数を数えておく
        for (long long next : G[i])
        {
            ind[next]++;
        }
    }
    queue<long long> que;
    for (long long i = 0; i < n; i++)
    { // 次数が0の点をキューに入れる
        if (ind[i] == 0)
            que.push(i);
    }
    while (!que.empty())
    { // 幅優先探索
        long long now = que.front();
        ans.push_back(now);
        que.pop();
        for (long long next : G[now])
        {
            ind[next]--;
            if (ind[next] == 0)
            {
                que.push(next);
            }
        }
    }
    return ans;
}
/* 
    topo_sort(G): グラフG をトポロジカルソート
    返り値: トポロジカルソートされた頂点番号を持つ配列
    計算量: O(|E|+|V|)
    頂点間の距離も管理するときは構造体をつくること
*/
int main()
{
    cout << fixed << setprecision(30);
    ll N, M;
    cin >> N >> M;
    vector<vector<ll>> G(N);
    loop(i, N - 1 + M)
    {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
    }
    vector<ll> data = topo_sort(G);
    vector<ll> par(N, -1);
    loop(i, N)
    {
        ll now = data[i];
        ll siz = G[now].size();
        loop(j, siz)
        {
            ll next = G[now][j];
            par[next] = now;
        }
    }
    loop(i, N) putout(par[i] + 1);
    return 0;
}
