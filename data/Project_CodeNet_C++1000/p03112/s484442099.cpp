#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
#include <math.h>
#include <bitset>
#include <queue>
#include <set>
#include <iomanip>
#include <assert.h>
#include <cstdio>

// #include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr long long int INFLL = 1001001001001001LL;
constexpr long long int infll = 1001001001001001LL;
constexpr int INF = 1000000007;
constexpr int inf = 1000000007;
const int mod = 1000000007;

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

ll gcd(ll a, ll b)
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

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

template <typename T>
T seinomi(T a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return 0;
    }
}

//連想配列[素因数f.first][個数f.second]
template <typename T>
map<T, T> soinsuubunkai(T n)
{
    map<T, T> ret;
    for (T i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ret[i]++;
            n /= i;
        }
    }
    if (n != 1)
        ret[n] = 1;
    return ret;
}

//桁数取得
template <typename T>
T ketasuu(T num)
{
    return std::to_string(num).length();
}

//階乗
ll kaizyou(ll k)
{
    ll sum = 1;
    for (ll i = 1; i <= k; ++i)
    {
        sum *= i;
    }
    return sum;
}

//階乗を(10^9)+7で割った余り
ll modkaizyou(ll k)
{
    ll sum = 1;
    for (int i = 1; i <= k; ++i)
    {
        sum *= i;
        sum = sum % mod;
    }
    return sum;
}

template <class ForwardIt, class T>
void iota(ForwardIt first, ForwardIt last, T value)
{
    while (first != last)
    {
        *first++ = value;
        ++value;
    }
}

//整数乗
ll llpow(ll a, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        ll rep = a;
        for (ll i = 1; i < n; i++)
        {
            rep *= a;
        }
        return rep;
    }
}

long long modpow(long long a, long long n, long long mod)
{
    long long res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

template <typename T>
T amarinasi(T a, T b)
{
    if (a % b == 0)
    {
        return a / b;
    }
    else if (a % b > 0)
    {
        return a / b + 1;
    }
    else
    {
        return a / b - 1;
    }
}

//組み合わせ nCr
vector<vector<ll>> nCr_v(5010, vector<ll>());
bool nCr_maekeisan = false;
void nCr_Calculater()
{
    for (int i = 0; i < 5010; i++)
    {
        nCr_v[i][0] = 1;
        nCr_v[i][i] = 1;
    }
    for (int k = 1; k < 5010; k++)
    {
        for (int j = 1; j < k; j++)
        {
            nCr_v[k][j] = (nCr_v[k - 1][j - 1] + nCr_v[k - 1][j]);
        }
    }
}
ll nCr(ll n, ll r)
{
    if (n > 5010 || n < 0 || r > 5010 || r < 0)
    {
        cout << "Error!! n or r is over 5010 or under 0" << endl;
        return 1;
    }
    else
    {
        if (nCr_maekeisan == false)
        {
            for (ll i = 0; i < 5010; i++)
            {
                nCr_v[i].resize(5010);
            }
            nCr_Calculater();
            nCr_maekeisan = true;
        }
        return nCr_v[n][r];
    }
}

// テーブル生成版(0<=k<=n<=10^6)　組み合わせnCr 10^9+7で割った余り
vector<ll> modnCr_fac, modnCr_finv, modnCr_inv;
bool modnCr_maekeisan = false;
void COMinit()
{
    modnCr_fac[0] = modnCr_fac[1] = 1;
    modnCr_finv[0] = modnCr_finv[1] = 1;
    modnCr_inv[1] = 1;
    for (int i = 2; i < 1000010; i++)
    {
        modnCr_fac[i] = modnCr_fac[i - 1] * i % mod;
        modnCr_inv[i] = mod - modnCr_inv[mod % i] * (mod / i) % mod;
        modnCr_finv[i] = modnCr_finv[i - 1] * modnCr_inv[i] % mod;
    }
}
ll COM(ll n, ll k)
{
    if (n < k)
        return 0;
    if (n < 0 || k < 0)
        return 0;
    return modnCr_fac[n] * (modnCr_finv[k] * modnCr_finv[n - k] % mod) % mod;
}
ll modnCr(ll n, ll r)
{
    if (modnCr_maekeisan == false)
    {
        modnCr_fac.resize(1000010);
        modnCr_finv.resize(1000010);
        modnCr_inv.resize(1000010);
        COMinit();
        modnCr_maekeisan = true;
    }
    return COM(n, r);
}

//単発版(nが大きくrが小さい場合)　組み合わせnCr　10^9+7で割った余り
long long modnCr2(long long n, long long a)
{
    long long ans = 1, ans1 = 1;
    for (long long i = n - a + 1; i <= n; i++)
    {
        ans *= i % mod;
        ans %= mod;
    }

    for (long long i = 2; i <= a; i++)
        ans1 = (ans1 * i) % mod;
    ans1 = modpow(ans1, mod - 2, mod);
    return ((ans % mod) * ans1) % mod;
}

//順列　nPr
ll nPr(ll n, ll r)
{
    r = n - r;
    ll sum = 1;
    ll i;
    for (i = n; i >= r + 1; i--)
        sum *= i;
    return sum;
}

//重複組み合わせ　nHr = (r+n-1)Cr
ll nHr(ll n, ll r)
{
    return modnCr(r + n - 1, r);
}

//弧度法から度数法に変換
double to_deg(double r)
{
    return r * 180.0 / (atan(1.0) * 4.0);
}

//座標から度数法の角度に変換
double kakudo(double dx, double dy)
{
    return atan2(dx, dy) * 180.0 / (atan(1.0) * 4.0);
}

//約数列挙配列(1を必ず含むことに注意)
vector<ll> yakusuu(ll n)
{
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ret.push_back(i);
            if (i * i != n)
                ret.push_back(n / i);
        }
    }
    sort(begin(ret), end(ret));
    return (ret);
}

//素数判定bool型配列
std::vector<bool> sosuuhantei(ll max)
{
    vector<bool> ret;
    if (max + 1 > ret.size())
    {                              // resizeで要素数が減らないように
        ret.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    ret[0] = false; // 0は素数ではない
    ret[1] = false; // 1は素数ではない

    for (ll i = 2; i * i <= max; ++i)
    { // 0からsqrt(max)まで調べる
        if (ret[i])
        { // iが素数ならば
            for (ll j = 2; i * j <= max; ++j)
            {                       // (max以下の)iの倍数は
                ret[i * j] = false; // 素数ではない
            }
        }
    }
    return (ret);
}

//素数列挙longlong型配列
std::vector<ll> sosuurekkyo(ll max)
{
    vector<bool> tmp;
    vector<ll> ret;
    if (max + 1 > tmp.size())
    {                              // resizeで要素数が減らないように
        tmp.resize(max + 1, true); // IsPrimeに必要な要素数を確保
    }
    tmp[0] = false; // 0は素数ではない
    tmp[1] = false; // 1は素数ではない

    for (ll i = 2; i * i <= max; ++i)
    { // 0からsqrt(max)まで調べる
        if (tmp[i])
        { // iが素数ならば
            for (ll j = 2; i * j <= max; ++j)
            {                       // (max以下の)iの倍数は
                tmp[i * j] = false; // 素数ではない
            }
        }
    }
    for (ll i = 0; i <= max; i++)
    {
        if (tmp[i])
        {
            ret.push_back(i);
        }
    }
    return (ret);
}

//十進数を二進数にしたときの桁数
ll nisinsize(ll n)
{
    ll rep = 0;
    ll tmp = 1;
    while (1)
    {
        rep++;
        tmp *= 2;
        if (tmp > n)
        {
            break;
        }
    }
    return rep;
}

//UnionFind木
struct UnionFind
{
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> siz;
    UnionFind(ll N) : par(N), siz(N)
    { //最初は全てが根であるとして初期化
        for (ll i = 0; i < N; i++)
        {
            par[i] = i;
            siz[i] = 1;
        }
    }

    ll root(ll x)
    { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y)
    {                    // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry)
            return; //xとyの根が同じ(=同じ木にある)時はそのまま
        if (siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
        return; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    ll size(ll x)
    { // 素集合のサイズ
        return siz[root(x)];
    }

    bool same(ll x, ll y)
    { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }
};

//進数変換
class base_convert
{
private:
    const char *s;
    int a[128];

public:
    base_convert(const char *s = "0123456789ABCDEF") : s(s)
    {
        int i;
        for (i = 0; s[i]; ++i)
            a[(int)s[i]] = i;
    }
    std::string to(long long p, int q)
    {
        int i;
        if (!p)
            return "0";
        char t[64] = {};
        for (i = 62; p; --i)
        {
            t[i] = s[p % q];
            p /= q;
        }
        return std::string(t + i + 1);
    }
    std::string to(const std::string &t, int p, int q)
    {
        return to(to(t, p), q);
    }
    long long to(const std::string &t, int p)
    {
        int i;
        long long sm = a[(int)t[0]];
        for (i = 1; i < (int)t.length(); ++i)
            sm = sm * p + a[(int)t[i]];
        return sm;
    }
};

vector<vector<ll>> bit_zentansaku(ll base, ll n)
{
    vector<vector<ll>> res(llpow(base, n), vector<ll>(n));
    base_convert r;
    for (ll mask = 0; mask < res.size(); mask++)
    {
        string tmp = r.to(mask, base);

        while (tmp.size() < n)
        {
            tmp.insert(0, "0");
        }
        for (ll i = 0; i < n; i++)
        {
            res[mask][i] = tmp[i] - '0';
        }
    }
    return (res);
}

//小数点以下10桁テンプレート（main関数内の最初に貼付け）
//std::cout << std::fixed << std::setprecision(10);

//----------------------------------------------------------------

int main()
{
    ll a, b, q;
    cin >> a >> b >> q;
    vector<ll> s(a + 1);
    vector<ll> t(b + 1);
    s[0] = (-infll);
    t[0] = (-infll);
    for (ll i = 1; i < a + 1; i++)
    {
        cin >> s[i];
    }
    for (ll i = 1; i < b + 1; i++)
    {
        cin >> t[i];
    }
    s.push_back(infll);
    t.push_back(infll);
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (ll i = 0; i < q; i++)
    {
        ll x;
        cin >> x;
        auto e_t = lower_bound(s.begin(), s.end(), x);
        auto w_t = e_t;
        w_t--;
        auto e_s = lower_bound(t.begin(), t.end(), x);
        auto w_s = e_s;
        w_s--;
        ll tmp1 = max((ll)x - *w_t, (ll)x - *w_s);
        ll tmp2 = max(*e_t - x, *e_s - x);
        ll tmp3 = min(x - *w_t, *e_s - x) * 2 + max(x - *w_t, *e_s - x);
        ll tmp4 = min(x - *w_s, *e_t - x) * 2 + max(x - *w_s, *e_t - x);
        ll ans = min({tmp1, tmp2, tmp3, tmp4});
        cout << ans << endl;
    }
}
