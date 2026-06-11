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
string s;
ll n,q;
vector<ll> k;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n>>s>>q;
    for (int i = 0; i < q; i++)
    {
        ll temp;
        cin >> temp;
        k.push_back(temp);
    }
    vector<ll> dp(n+1,0);//i文字まであったdのかず
    vector<ll> dp1(n+1,0);//dm
    vector<ll> dpm(n+1,0);
   //vector<ll> dp2(n+1,0);//dmc
   ll count=0;
   ll count1=0;
    rep(i,n){
        if(s[i]=='D'){
            count++;
        }
        if(s[i]=='M')count1++;
            dpm[i]=count1;
            dp[i]=count;
    }
    for(int i=1;i<n;i++){
        if(s[i]=='M'){
            dp1[i]=dp[i-1]+dp1[i-1];
        }
        else{
            dp1[i]=dp1[i-1];
        }
    }
    /*
    for(int i=2;i<n;i++){
        if(s[i]=='C'){
            dp2[i]=dp1[i]+dp2[i-1];
        }
        else{
            dp2[i]=dp2[i-1];
        }
    }
    */
    //debug(dp);
    //debug(dp1);
    //debug(dpm);
    rep(i,q){
        vector<ll> dp2(n+1,0);//dmc
        for(ll j=0;j<n;j++){
            ll ktemp=min(k[i]-1,j);
            dp2[j]=dp1[j]-dp1[j-ktemp];
            if(j-k[i]+1>=0){
                //cout<<j<<" "<<dp[j-ktemp]*(dpm[j]-dpm[j-ktemp])<<"\n";
            dp2[j]-=dp[j-ktemp]*(dpm[j]-dpm[j-ktemp]);
            }
        }
        //debug(dp2);
        ll res=0;
        for(int j=1;j<n;j++){
            if(s[j]=='C'){
                res+=dp2[j-1];
            }
        }
        cout<<res<<"\n";
    }
}
