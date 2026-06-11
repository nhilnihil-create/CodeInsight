//解説ゾロリ
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
long long modpow(long long a, long long n)
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
long long modinv(long long a)
{
    return modpow(a, mod - 2);
}
vec fact(3000001);    //fact[i]=(i!)
vec factinv(3000001); //factinv[i]=(i!)^-1
void COMinit()
{
    long long now = 1;
    fact[0] = 1;
    factinv[0] = modinv(0);
    Loop(i, 1, 3000001)
    {
        now *= i;
        now %= mod;
        fact[i] = now;
        factinv[i] = modinv(now);
    }
}
long long COM(long long n, long long r)
{
    if (n < r)
        return 0;
    if (n < 0 || r < 0)
        return 0;
    if (n == r)
        return 1;
    if (r == 0)
        return 1;
    long long ans = fact[n];
    ans *= factinv[r];
    ans %= mod;
    ans *= factinv[n - r];
    ans %= mod;
    return ans;
}
int main()
{
    cout << fixed << setprecision(30);
    ll n;
    cin >> n;
    putout(0);
    string s1;
    cin>>s1;
    if(s1=="Vacant")return 0;
    putout(n-1);
    string s2;
    cin>>s2;
    if(s2=="Vacant")return 0;
    ll r=n-1,l=0;
    //male=0,female=1;
    ll rcolor,lcolor;
    if(s1=="Male"){
        lcolor=0,rcolor=1;
    }
    else{
        lcolor=1,rcolor=0;
    }
    while(true){
        ll mid=(r+l)/2;
        putout(mid);
        string ss;
        cin>>ss;
        if(ss=="Vacant")return 0;
        ll midcolor;
        if(ss=="Male")midcolor=0;
        else midcolor=1;
        if(abs(r-mid-1)%2==0){
            if(rcolor==midcolor){
                l=mid+1;
                lcolor=1-rcolor;
                continue;
            }
        }
        else{
            if (rcolor != midcolor)
            {
                l = mid + 1;
                lcolor = rcolor;
                continue;
            }
        }
        if(abs(mid-l-1)%2==0){
            if (lcolor == midcolor)
            {
                r = mid - 1;
                rcolor = abs(1 - lcolor);
                continue;
            }
        }
        else{
            if (lcolor != midcolor)
            {
                r = mid - 1;
                rcolor = lcolor;
                continue;
            }
        }
    }
    return 0;
}