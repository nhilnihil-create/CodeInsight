#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) x.begin(),x.end()
#define pll  pair <long long,long long>
#define ss second
#define ff first
#define inf 9223372036854775807
#define mod 1000000007
#define ld long double
#define fast  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bug(x) cout << #x <<": " << x << '\n';
const ll N=201 ;
int numPermsDISequence(string s) {

int n=s.length() ;
vector<int>dp(n+2,0),pre(n+2,0) ;
dp[1]=1 ;
pre[1]=1 ;
for(int i=2;i<=n+1;i++) pre[i]=1 ;


for(int i=2;i<=n+1;i++)
{
for(int j=1;j<=i;j++) // last
{
 dp[j]=0 ;
 if(s[i-2]=='>')
 {
   //for(int k=j;k<i;k++) dp[i][j]=(dp[i][j]+dp[i-1][k])%mod ;
   dp[j]=(pre[i-1]-pre[j-1]+mod)%mod ;
 }
else
 {
   //for(int k=1;k<j;k++)  dp[i][j]=(dp[i][j]+dp[i-1][k])%mod ;
   dp[j]=(pre[j-1]-pre[0]+mod)%mod ;
 }
}
pre[0]=dp[0] ;
for(int i=1;i<=n+1;i++)
{
    pre[i]=(pre[i-1]+dp[i])%mod ;
}

}

return pre[n+1]%mod ;

}
int main()
{
    fast ;
    ll n ; cin>>n ;
    string s ; cin>>s ;
    cout<<numPermsDISequence(s) ;



}

