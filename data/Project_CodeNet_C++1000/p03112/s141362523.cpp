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
ll a,b,q;
vector<ll> s,t,x;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> a>>b>>q;
    s.resize(a);
    t.resize(b);
    x.resize(q);
    rep(i,a){
        cin>>s[i];
    }
    rep(i,b){
        cin>>t[i];
    }
    rep(i,q){
        cin>>x[i];
    }
    vector<ll> c(q),d(q),ans(q);
    rep(i,q){
        c[i]=lower_bound(ALL(s),x[i])-s.begin();
        d[i]=lower_bound(ALL(t),x[i])-t.begin();
    }
    rep(i,q){
        ll score=LINF;
        if(c[i]!=a&&d[i]!=b){
            ll temp=max(abs(s[c[i]]-x[i]),abs(t[d[i]]-x[i]));
            chmin(score,temp);
        }
        if(c[i]!=0&&d[i]!=0){
            ll temp=max(abs(s[c[i]-1]-x[i]),abs(t[d[i]-1]-x[i]));
            chmin(score,temp);
        }
        if(c[i]!=0&&d[i]!=b){
            ll temp=max(abs(s[c[i]-1]-x[i]),abs(t[d[i]]-x[i]));
            ll temp1=min(abs(s[c[i]-1]-x[i]),abs(t[d[i]]-x[i]));
            chmin(score,temp1*2+temp);
        }
        if(c[i]!=a&&d[i]!=0){
            ll temp=max(abs(s[c[i]]-x[i]),abs(t[d[i]-1]-x[i]));
            ll temp1=min(abs(s[c[i]]-x[i]),abs(t[d[i]-1]-x[i]));
            chmin(score,temp1*2+temp);
        }
        ans[i]=score;
    }
    rep(i,q)
    cout << ans[i] << "\n";
}
