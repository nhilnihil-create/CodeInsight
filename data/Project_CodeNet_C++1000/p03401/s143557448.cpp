#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n;
    cin >>n;
    vector<ll>dp(n+1),a(n);
    int pre;
    rep(i,n)
    {
        
        cin >>a[i];
        if(!i)dp[i]=abs(a[i]);
        else dp[i]=abs(a[i]-pre)+dp[i-1];
      
        pre=a[i];
    }
    dp[n]=dp[n-1]+abs(pre);
 
    rep(i,n)
    {
        if(!i)cout<<abs(a[1])+dp[n]-dp[1]<<endl;
        else if(i==n-1)cout<<abs(a[n-2])+dp[n-2]<<endl;
        else
        {
            cout<<dp[n]-(dp[i+1]-dp[i-1])+abs(a[i+1]-a[i-1])<<endl;
        }
        
    }
    
    return 0;
}