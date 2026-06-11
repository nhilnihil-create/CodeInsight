#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using vec = vector<ll>;
using vect = vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i, n) for (register int i = 0; i < n; i++)
#define Loop(i, m, n) for (ll i = m; i < n; i++)
#define pool(i, n) for (register int i = n; i >= 0; i--)
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
static struct IO
{
    char tmp[1 << 10];
    // fast input routines
    char cur;

    //#define nextChar() (cur = getc_unlocked(stdin))
    //#define peekChar() (cur)
    inline char nextChar() { return cur = getc_unlocked(stdin); }
    inline char peekChar() { return cur; }

    inline operator bool() { return peekChar(); }
    inline static bool isBlank(char c) { return (c < '-' && c); }
    inline bool skipBlanks()
    {
        while (isBlank(nextChar()))
            ;
        return peekChar() != 0;
    }

    inline IO &operator>>(char &c)
    {
        c = nextChar();
        return *this;
    }

    inline IO &operator>>(char *buf)
    {
        if (skipBlanks())
        {
            if (peekChar())
            {
                *(buf++) = peekChar();
                while (!isBlank(nextChar()))
                    *(buf++) = peekChar();
            }
            *(buf++) = 0;
        }
        return *this;
    }

    inline IO &operator>>(string &s)
    {
        if (skipBlanks())
        {
            s.clear();
            s += peekChar();
            while (!isBlank(nextChar()))
                s += peekChar();
        }
        return *this;
    }

    inline IO &operator>>(double &d)
    {
        if ((*this) >> tmp)
            sscanf(tmp, "%lf", &d);
        return *this;
    }

#define defineInFor(intType)                         \
    inline IO &operator>>(intType &n)                \
    {                                                \
        if (skipBlanks())                            \
        {                                            \
            int sign = +1;                           \
            if (peekChar() == '-')                   \
            {                                        \
                sign = -1;                           \
                n = nextChar() - '0';                \
            }                                        \
            else                                     \
                n = peekChar() - '0';                \
            while (!isBlank(nextChar()))             \
            {                                        \
                n += n + (n << 3) + peekChar() - 48; \
            }                                        \
            n *= sign;                               \
        }                                            \
        return *this;                                \
    }

    defineInFor(int)
        defineInFor(unsigned int)
            defineInFor(long long)

        // fast output routines

        //#define putChar(c) putc_unlocked((c), stdout)
        inline void putChar(char c)
    {
        putc_unlocked(c, stdout);
    }
    inline IO &operator<<(char c)
    {
        putChar(c);
        return *this;
    }
    inline IO &operator<<(const char *s)
    {
        while (*s)
            putChar(*s++);
        return *this;
    }

    inline IO &operator<<(const string &s)
    {
        for (int i = 0; i < (int)s.size(); ++i)
            putChar(s[i]);
        return *this;
    }

    char *toString(double d)
    {
        sprintf(tmp, "%lf%c", d, '\0');
        return tmp;
    }
    inline IO &operator<<(double d) { return (*this) << toString(d); }

#define defineOutFor(intType)                   \
    inline char *toString(intType n)            \
    {                                           \
        char *p = (tmp + 30);                   \
        if (n)                                  \
        {                                       \
            bool isNeg = 0;                     \
            if (n < 0)                          \
                isNeg = 1, n = -n;              \
            while (n)                           \
                *--p = (n % 10) + '0', n /= 10; \
            if (isNeg)                          \
                *--p = '-';                     \
        }                                       \
        else                                    \
            *--p = '0';                         \
        return p;                               \
    }                                           \
    inline IO &operator<<(intType n) { return (*this) << toString(n); }

    defineOutFor(int)
        defineOutFor(long long)

#define endl ('\n')
#define cout __io__
#define cin __io__
} __io__;
int main()
{
    register int N, K;
    cin >> N >> K;
    vector<int> t(N), d(N);
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
    vector<pair<int, int>> pairs(N);
    loop(i, N) pairs[i] = make_pair(d[i], t[i]);
    sort(all(pairs));
    pool(i, N - 1)
    {
        t[N - 1 - i] = pairs[i].second;
        d[N - 1 - i] = pairs[i].first;
    }
    //番兵を一応追加
    t.push_back(100008);
    d.push_back(-1e18 + 9);
    ll kind = 0;                      //種類
    vector<bool> seen(100010, false); //その種類が既に集合にあるか
    vector<int> num(100010);          //個数
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
    for (register int i = K - 1; i >= 0; i--)
    {
        if (num[t[i]] > 1)
        {
            trade.emplace_back(d[i]);
            num[t[i]]--;
        }
    }
    //残りのN-K個について見ていく
    register int ind = 0;
    register ll preans = ans;
    loop(i, N - K)
    {
        if (!seen[t[K + i]] && ind != trade.size())
        {
            seen[t[K + i]] = true;
            preans += d[K + i] + 2 * kind + 1 - trade[ind];
            kind++;
            if (preans > ans)
                ans = preans;
            ind++;
        }
    }
    cout << ans << ' ';
    return 0;
}
