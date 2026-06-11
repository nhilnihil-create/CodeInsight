//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int mod = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll n;
string s;
// 繰り返し二乗法
ll pow_mod(ll x, ll n)
{
    if (n == 0)
        return 1;
    ll ret = pow_mod((x * x) % mod, n / 2);
    if (n & 1)
        ret = (ret * x) % mod;
    return ret;
}
ll inv_mod(ll n)
{
    // フェルマーの小定理
    return pow_mod(n, mod - 2);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>s;
    map<char,ll> m;
    //map<char, ll> mans;
    ll ans=0;
    ll kumi=1;
    for (int i = 0; i < n; i++)
    {
        m[s[i]]++;
        if (m[s[i]] == 1)
        {
            ans += kumi;
            kumi*=2;
        }
        else{
            kumi*=inv_mod(m[s[i]]);
            kumi%=mod;
            ans+=kumi;
            kumi*=m[s[i]]+1;
        }
        kumi%=mod;
        ans%=mod;
    }
    cout << ans << "\n";
}
