//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18) + 1;
const int MOD = 1000000007;
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
ll t;
bool func(ll a,ll b,ll g,ll d){
    //cout<<g<<"\n";
    ll x=a%g+((b-a%g+g)/g)*g;
    //cout<<x<<"\n";
    if(x<d)return false;
    else return true;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a<b){
            no;continue;
        }
        if(b>d){
            no;continue;
        }
        ll kouyaku=gcd(b,d);
        if(func(a,c,kouyaku,b))yes;
        else no;
    }
    //https://scrapbox.io/ganariya/AtCoderGrandContest026_B問題600点「rng_10s」_(copy)
}
