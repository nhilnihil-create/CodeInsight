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
#define mod 1000000007ll;
#define setbit bitset<8>
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define count2way(v, x) high2way(v, x) - low2way(v, x)
#define lower(v, x) low2way(v, x) - v.begin()       //1番左が0、もし見つから無いならｎを出力
#define higher(v, x) high2way(v, x) - v.begin() - 1 //1番左が0、もし見つからないならn-1を出力（注意）
#define putout(a) cout << a << endl
#define putout2(a, b) \
    putout(a);        \
    putout(b)
#define putout3(a, b, c) \
    putout(a);           \
    putout(b);           \
    putout(c)
#define putout4(a, b, c, d) \
    putout(a);              \
    putout(b);              \
    putout(c);              \
    putout(d)
#define putout5(a, b, c, d, e) \
    putout(a);                 \
    putout(b);                 \
    putout(c);                 \
    putout(d);                 \
    putout(e)
#define Gput(a, b) G[a].push_back(b)
#define cin1(a) cin >> a
#define cin2(a, b) cin >> a >> b
#define cin3(a, b, c) cin >> a >> b >> c
#define cin4(a, b, c, d) cin >> a >> b >> c >> d
#define cin5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define sum(v) accumulate(all(v), 0ll)
#define gcd(x, y) __gcd(x, y)
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}
template <typename T>
T lcm(T x, T y)
{
    T z = gcd(x, y);
    return x * y / z;
}

template <typename T>
T primejudge(T n)
{
    if (n < 2)
        return 0;
    else if (n == 2)
        return 1;
    else if (n % 2 == 0)
        return 0;
    double sqrtn = sqrt(n);
    Loop(i, 3, sqrtn + 1)
    {
        if (n % i == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
template <typename T>
T modinv(T a, T m)
{
    T b = m, u = 1, v = 0;
    while (b)
    {
        T t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= m;
    if (u < 0)
        u += m;
    return u;
}
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//多次元配列の宣言法
//vector<vector<ll>> field(h, vector<ll>(w));
template <class T>
inline void chmax(T &a, T b)
{
    if (a < b)
        a = b;
}
template <class T>
inline void chmin(T &a, T b)
{
    if (a > b)
        a = b;
}
/*
ライブラリをここに置いてコメントを削除
*/
/*
union_find木で出来ること
1.要素xと要素yが同じグループに属するか判定
2.要素xが属する木と要素yが属するグループの併合
※グループの分割が出来ないことに注意！
計算量O(α(N))
*/
struct union_find
{
    vec par; //par[i]:iの親の番号　
    vec rank;
    //初期化子リストを用いた初期化
    union_find(ll N) : par(N), rank(N)
    {
        loop(i, N)
        {
            par[i] = i;
            rank[i] = 0;
        }
    }
    //要素xが所属する木の根を再帰的に発見する
    ll root(ll x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]); //経路圧縮
    }
    //要素xが属する木と要素yが属する木の併合
    void unite(ll x, ll y)
    {
        ll rx = root(x);
        ll ry = root(y);
        if (rx == ry)
            return; //同じ木に属してたらそのまま
        if (rank[rx] < rank[ry])
        {
            par[rx] = ry; //根がryの木に併合
        }
        else
        {
            par[ry] = rx; //根がrxの木に併合
            if (rank[rx] == rank[ry])
                rank[rx]++;
        }
    }
    //要素xが属する木と要素yが属する木が同じならtrueを返す
    bool same(ll x, ll y)
    {
        return root(x) == root(y);
    }
};
int main()
{
    ll n, m;
    cin >> n >> m;
    vec p(n);
    vec x(m);
    vec y(m);
    loop(i, n) cin >> p[i];
    union_find tree(n);
    loop(i, m)
    {
        ll a, b;
        cin >> a >> b;
        x[i] = a - 1;
        y[i] = b - 1;
        tree.unite(x[i], y[i]);
    }
    ll ans = 0;
    loop(i, n) if (tree.same(p[i] - 1, i)) ans++;
    putout(ans);
    return 0;
}