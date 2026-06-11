#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
vector<int> dy={-1,0,1,0},dx={0,-1,0,1};
ll dp[200000][5];
int main(){
 string s;
 cin>>s;
 int n=s.size();
 dp[0][0]=1;
 for(int i=0;i<n;i++){
     for(int j=0;j<5;j++){
         if(s[i]!='?')dp[i+1][j]+=dp[i][j];
         else dp[i+1][j]+=dp[i][j]*3;
         dp[i+1][j]%=mod;
     }
     if(s[i]=='A'||s[i]=='?')dp[i+1][1]+=dp[i][0];
     if(s[i]=='B'||s[i]=='?')dp[i+1][2]+=dp[i][1];
     if(s[i]=='C'||s[i]=='?')dp[i+1][3]+=dp[i][2];
     for(int j=1;j<=3;j++){
           dp[i+1][j]%=mod;
     }
 }
 cout<<dp[n][3]<<endl;
}

