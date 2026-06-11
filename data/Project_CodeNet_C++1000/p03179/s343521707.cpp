#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<double, double>P;
typedef tuple<ll, int, int>T;
#define PI 3.14159265358979
#define MOD (ll)1000000007
typedef vector<ll> vec;
typedef vector<vec> mat;

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  ll dp[N][N];
  rep(i,N){
  	rep(j,N){
      dp[i][j]=0ll;
    }
  }
  rep(i,N){dp[0][i]=1ll;}
  
  rep(i,N-1){
    ll sum[N+1];
    rep(j,N){sum[j]=0ll;}
    sum[1]=dp[i][0];
    rep(j,N){sum[j+1]=sum[j]+dp[i][j];sum[j+1]%=MOD;}
    rep(j,N){
      if(S[i]=='<'){
        dp[i+1][j]=(sum[j+1])%MOD;
      }
      if(S[i]=='>'){
        dp[i+1][j]=(sum[N-i]-sum[j+1]+MOD)%MOD;
      }
    }
  }
  cout<<dp[N-1][0]<<endl;
}