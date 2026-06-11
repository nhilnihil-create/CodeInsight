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
ll n, m;
vector<ll> a;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>m;
    map<ll,ll>ma;
    ma[1]=2;
    ma[2]=5;
    ma[3]=5;
    ma[4]=4;
    ma[5]=5;
    ma[6]=6;
    ma[7]=3;
    ma[8]=7;
    ma[9]=6;
    for (int i = 0; i < m; i++)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<string> dp(n+10,"0");
    dp[0]="";
    rep(i,n+1){
        if(dp[i]=="0")continue;
        rep(j,m){
            if(dp[i+ma[a[j]]].size()==dp[i].size()+1){
                char temp=a[j]+'0';
                string temp1=dp[i]+temp;
                if(temp1>dp[i+ma[a[j]]]){
                    //cout<<temp1<<" "<<dp[i+ma[a[j]]]<<"\n";
                    dp[i+ma[a[j]]]=temp1;
                }
            }
            else{
                if(dp[i+ma[a[j]]].size()<dp[i].size()+1){
                    char temp=a[j]+'0';
                    dp[i+ma[a[j]]]=dp[i]+temp;
                }
            }
        }
        //debug(dp);
    }
    cout << dp[n] << "\n";
}
