#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

ll n;
string s;
ll dp[3009][3009];
ll sum[3009][3009];
int main(){
    cin>>n>>s;
    ll maki=s.length();
    maki++;
    for(ll i=1;i<=n;i++)dp[0][i]=1;
    for(ll i=1;i<maki;i++){
        for(ll j=1;j<=i+1;j++){
            if(s[i-1]=='>')dp[i][j]=dp[i-1][n]-dp[i-1][j-1]+mod;
            else dp[i][j]=dp[i-1][j-1];
            dp[i][j]%=mod;
        }
        for(ll j=1;j<=n;j++)dp[i][j]+=dp[i][j-1],dp[i][j]%=mod;
    }
    cout << dp[n-1][n] <<endl;
    return 0;
}

