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
#define flagcount __builtin_popcount
#define flag(x) (1 << x)
#define flagadd(bit, x) bit |= flag(x)
#define flagpop(bit, x) bit &= ~flag(x)
#define flagon(bit, i) bit &flag(i)
#define flagoff(bit, i) !(bit & (1 << i))
#define all(v) v.begin(), v.end()
#define low2way(v, x) lower_bound(all(v), x)
#define high2way(v, x) upper_bound(all(v), x)
#define idx_lower(v, x) (distance(v.begin(), low2way(v, x)))  //配列vでx未満の要素数を返す
#define idx_upper(v, x) (distance(v.begin(), high2way(v, x))) //配列vでx以下の要素数を返す
#define idx_lower2(v, x) (v.size() - idx_lower(v, x))         //配列vでx以上の要素数を返す
#define idx_upper2(v, x) (v.size() - idx_upper(v, x))         //配列vでxより大きい要素の数を返す
#define putout(a) cout << a << endl
#define Gput(a, b) G[a].push_back(b)
#define Sum(v) accumulate(all(v), 0ll)
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
//場合によって使い分ける
//const ll dx[4]={1,0,-1,0};
//const ll dy[4]={0,1,0,-1};
const ll dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//2次元配列の宣言
//vector<vector<ll>> field(h, vector<ll>(w));

template <typename T>
struct BIT
{
    int n;            // 要素数
    vector<T> bit[2]; // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_)
    {
        n = n_ + 1;
        for (int p = 0; p < 2; p++)
            bit[p].assign(n, 0);
    }

    void add_sub(int p, int i, T x)
    {
        for (int idx = i; idx < n; idx += (idx & -idx))
        {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x)
    { // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }

    T sum_sub(int p, int i)
    {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx))
        {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }

    // [l,r) の区間和を取得
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
};
/* 
    BIT: RAQ対応BIT
    BIT<ll> data(n)等で宣言
    構造体内の関数はdata.add(l,r,x)等で使用
    初期値は a_1 = a_2 = ... = a_n = 0
    ・add(l,r,x): [l,r) に x を加算する
    ・sum(i): a_1 + a_2 + ... + a_i を計算する
    ・query(l,r):[l,r)の区間和を取得する
    計算量は全て O(logn)
*/
int main()
{
    cout << fixed << setprecision(30);
    ll N, M, Q;
    cin >> N >> M >> Q;
    vec L(M), R(M);
    vec p(Q), q(Q);
    loop(i, M)
    {
        cin >> L[i] >> R[i];
        L[i]--;
        R[i]--;
    }
    loop(i, Q)
    {
        cin >> p[i] >> q[i];
        p[i]--;
        q[i]--;
    }
    vector<vector<ll>> count(N, vector<ll>(N));
    loop(i, M)
    {
        count[L[i]][R[i]]++;
    }
    vector<BIT<ll>> ans;
    ans.assign(N, N);
    loop(i, N)
    {
        loop(j, N)
        {
            loop(k, i + 1)
            { //0~i
                ans[k].add(j + 1, N + 1, count[i][j]);
            }
        }
    }
    loop(i, Q)
    {
        putout(ans[p[i]].query(q[i] + 1, q[i] + 2));
    }
    return 0;
}
