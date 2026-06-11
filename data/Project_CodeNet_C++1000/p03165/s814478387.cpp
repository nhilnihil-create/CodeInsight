/**
*   Bismillahir Rahmanir Rahim.
*   Imtiaz_rafi
*   PCIU, CHITTAGONG
**/
#include<bits/stdc++.h>
using namespace std;
#define speed() ios::sync_with_stdio(0);cin.tie(0);
#define file() freopen ("input.txt", "r", stdin);freopen ("output.txt", "w", stdout);
#define rep(i,a) for(ll i=0;i<a;i++)
#define rep1(i,begin,end) for(ll i=begin;i<=end;i++)
#define trace(x) cerr << #x << " = " << x << endl
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define all(v)   v.begin(),v.end()
#define rall(v)   v.rbegin(),v.rend()
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define pi acos(-1)
#define en '\n'
// bitshift (1LL<<(3)) *2^3
typedef long long int ll;
typedef vector<ll>vi;
typedef map<ll,ll>mi;
typedef pair<ll,ll>pll;
typedef vector<pll> vll;
typedef set<ll>st;
typedef set<char>sc;
ll dx[] = {-1,+1,0,0,+1,-1,+1,-1};
ll dy[] = {0,0,-1,+1,+1,+1,-1,-1};
const ll mx = 3e3+123;
const ll MOD = 1e9+7;

template <class T> T power(T a,T b){a%=MOD;if(!a) return 0;T p=1;while(b>0){if(b&1){p*=a;p%=MOD;}a*=a;a%=MOD;b=b>>1;}return p;}
template <class T> void print(vector<T> &v){for(T u:v){cout<<u<<" ";}cout<<endl;}
template <class T> T gcd(T a, T b){return (b!=0?gcd<T>(b,a%b):a);}
template <class T> T lcm(T a, T b){return (a/gcd<T>(a,b)*b);}

ll BS(ll l,ll r,ll a[],ll k){ll mid,i=-1;while(l<=r){mid=(l+r)>>1;if(a[mid]==k){return i=mid;/*r=mid-1;*/}if(a[mid]<k) l=mid+1;if(a[mid]>k) r=mid-1;}return i;}
ll dp[mx][mx];
ll LCS(ll i,ll j,string &s,string &w) // O(n^2)
{
    if(i==s.size() || j==w.size())  return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    ll ans = 0;
    if(s[i]==w[j]){
        ans = 1+LCS(i+1,j+1,s,w);
    }
    else
    {
        ll x = LCS(i+1,j,s,w);
        ll y = LCS(i,j+1,s,w);
        ans = max(x,y);
    }
    return dp[i][j] = ans;
}
void showLCS(string &s,string &w,ll len)
{
    ll i=0,j=0;
    string str;
    while(len>0)
    {
        if(s[i]==w[j])
        {
            str+=s[i];
            i++;
            j++;
            len--;
        }
        else if(dp[i+1][j]>dp[i][j+1])
            i++;
        else
            j++;
    }
    cout<<str<<endl;
}

ll lcs(string s,string w)
{
    int m = s.size();
    int n = w.size();
    for(int i=0;i<=m;i++)
        dp[i][n] = 0;
    for(int j=0;j<=n;j++)
        dp[m][j] = 0;
    for(int i=m-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(s[i]==w[j])
                dp[i][j] = 1+dp[i+1][j+1];
            else
                dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[0][0];
}
void showlcs(string s,string t)
{
    ll i = s.size()-1;
    ll j = t.size()-1;
    string str;
    while(i>=0 && j>=0)
    {
        if(s[i]==t[j]){
            str+=s[i];
            i--;  j--;
        }
        else if(dp[i-1][j] > dp[i][j-1] )
            i--;
        else
            j--;
    }
    reverse(all(str));
    cout<<str<<en;
}

int main()
{
    speed();
    ll a,i,j;
    string s,t;
    cin>>s>>t;

    mem(dp,-1);
    a = LCS(0,0,s,t);
    showLCS(s,t,a);

    /*
    cout<<lcs(s,t)<<en;
    a = lcs(s,t);
    showlcs(s,t);
    */

return 0;
}
