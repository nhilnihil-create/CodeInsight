#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
using P=pair<int,int>;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
const ll mod=1000000007;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
ll dp[100005][4];
int main(){
  string s;
  cin>>s;
  int n=s.size();
  dp[0][0]=1;
  for(int i=0;i<n;i++){
      for(int j=0;j<4;j++){
          if(s[i]=='?')dp[i+1][j]+=dp[i][j]*3;
          else dp[i+1][j]+=dp[i][j];
          dp[i+1][j]%=mod;
      }
      if(s[i]=='A'||s[i]=='?')dp[i+1][1]+=dp[i][0];
      if(s[i]=='B'||s[i]=='?')dp[i+1][2]+=dp[i][1];
      if(s[i]=='C'||s[i]=='?')dp[i+1][3]+=dp[i][2];
      for(int j=0;j<4;j++){
          dp[i+1][j]%=mod;
      }
  }
  cout<<dp[n][3]<<endl;
}