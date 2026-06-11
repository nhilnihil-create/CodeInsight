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
#define flagcount(bit) __builtin_popcount(bit)
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
ll ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return -1;
}
template <typename T>
string make_string(T N)
{
    string ret;
    T now = N;
    while (now > 0)
    {
        T x = now % 10;
        ret += (char)('0' + x);
        now /= 10;
    }
    reverse(all(ret));
    return ret;
}
template <typename T>
T gcd(T a, T b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
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

int main()
{
    cout << fixed << setprecision(30);
    ll N, K;
    cin >> N >> K;
    vector<ll> t(N), d(N);
    loop(i, N)
    {
        cin >> t[i] >> d[i];
    }
    /*
    今現在x種類の寿司を食べたとき
    残りの中で価値が最大な寿司の価値をAとする
    新種の寿司ならば、
        それを食べるのが最適(+(A+2x+1))
    既存の寿司ならば、
        未知の寿司のなかで価値が最大の寿司の価値をBとする(ないなら-INF)
        このときはAとB+2x+1を比べる
        x++
    ↑↑↑↑↑これは嘘貪欲(サンプル2で撃墜)↑↑↑↑↑
    [正解法]
    K個貪欲に選んだ後、K個で種類がかぶっているやつがあれば、(なければ終了)
    それをすてて新種で価値が最大なものを選ぶということを繰り返す
    各試行で得られた解でK個貪欲解をchmaxで更新していく
    */
    vector<pair<ll, ll>> pairs(N);
    loop(i, N) pairs[i] = make_pair(d[i], t[i]);
    sort(all(pairs));
    reverse(all(pairs));
    loop(i, N)
    {
        t[i] = pairs[i].second;
        d[i] = pairs[i].first;
    }
    //番兵を一応追加
    t.push_back(100008);
    d.push_back(-1e18 + 9);
    ll kind = 0;                      //種類
    vector<bool> seen(100010, false); //その種類が既に集合にあるか
    vector<ll> num(100010);           //個数
    ll ans = 0;
    //K個貪欲
    loop(i, K)
    {
        ans += d[i];
        if (!seen[t[i]])
            kind++;
        seen[t[i]] = true;
        num[t[i]]++;
    }
    ans += kind * kind;
    //交換するのは既に2個以上あるもの
    //かぶっているのを小さい順にいれていけば良さそう
    vector<ll> trade;
    for (ll i = K - 1; i >= 0; i--)
    {
        if (num[t[i]] > 1)
        {
            trade.push_back(d[i]);
            num[t[i]]--;
        }
    }
    //残りのN-K個について見ていく
    ll ind = 0;
    ll preans = ans;
    loop(i, N - K)
    {
        if (!seen[t[K + i]] && ind != trade.size())
        {
            seen[t[K + i]] = true;
            preans -= trade[ind];
            preans += d[K + i];
            preans += 2 * kind + 1;
            kind++;
            ans = max(ans, preans);
            ind++;
        }
    }
    putout(ans);
    return 0;
}
