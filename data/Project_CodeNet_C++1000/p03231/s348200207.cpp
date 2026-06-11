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
int n, m;
string s,t;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>m>>s>>t;
    ll ans=lcm(n,m);
    ll temp1=ans/n;
    ll temp2=ans/m;
    ll temp3=lcm(temp1,temp2);
    ll temp4=temp3/temp1;
    ll temp5=temp3/temp2;
    ll a=1;
    ll b=1;
    while(true){
        if(a>s.size()||b>t.size()){
            break;
        }
        if(s[a-1]!=t[b-1])return cout<<-1<<"\n",0;
        a+=temp4;
        b+=temp5;
    }
    cout << ans << "\n";
}
