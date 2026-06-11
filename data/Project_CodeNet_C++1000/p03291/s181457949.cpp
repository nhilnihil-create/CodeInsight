#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
*/#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")    
using namespace std;
/*namespace mp = boost::multiprecision;
using Bint = mp::cpp_int;
using Real = mp::number<mp::cpp_dec_float<1024>>;
*/#define lli long long int
#define uli unsigned long long int
#define INF 999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(50) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 10000000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  lli A,B,C,D,E,H,W,M,K,L,R,N,num=0,sum=0,flag=0;string S,T;
  cin >> S;
  N=S.size();
  lli dp[114514][4];
  rep(i,0,114514)rep(j,0,4)dp[i][j]=0;
  dp[0][0]=1;
  if(S[0]=='A')dp[0][1]=1;
  else if(S[0]=='?'){
    dp[0][0]=3;
    dp[0][1]=1;
  }
  rep(i,1,N){
    if(S[i]!='?'){
      dp[i][0]=dp[i-1][0];
      if(S[i]=='A')dp[i][1]=(dp[i-1][1]+dp[i-1][0])%mod;
      else dp[i][1]=dp[i-1][1];
      if(S[i]=='B')dp[i][2]=(dp[i-1][2]+dp[i-1][1])%mod;
      else dp[i][2]=dp[i-1][2];
      if(S[i]=='C')dp[i][3]=(dp[i-1][3]+dp[i-1][2])%mod;
      else dp[i][3]=dp[i-1][3];
    }
    else{
      dp[i][0]=dp[i-1][0]*3%mod;
      dp[i][1]=(dp[i-1][1]*3+dp[i-1][0])%mod;
      dp[i][2]=(dp[i-1][2]*3+dp[i-1][1])%mod;
      dp[i][3]=(dp[i-1][3]*3+dp[i-1][2])%mod;
    }
  }
  /*rep(i,0,4){
    rep(j,0,N)cout << dp[j][i] << " ";
    Out("");
  }*/
  Out(dp[N-1][3]);
}