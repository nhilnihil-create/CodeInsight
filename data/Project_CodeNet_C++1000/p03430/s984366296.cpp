#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
template<class T> void chmin(T &a,const T &b){if(a>b) a=b;}
template<class T> void chmax(T &a,const T &b){if(a<b) a=b;}

string S;
int N,K;

string T;
int nxt[303][26];
int dp[303][303][303];

int rec(int uplef,int dwlef,int num){
    if(N-1-uplef<dwlef) return 0;
    if(N-1-dwlef<uplef) return 0;
    if(dp[uplef][dwlef][num]) return dp[uplef][dwlef][num];
    if(2*uplef>=N&&2*dwlef>=N) return 0;
    if(N%2&&uplef==N/2&&dwlef==N/2) return 1;

    int res=0;
    chmax(res,rec(uplef+1,dwlef,num));
    chmax(res,rec(uplef,dwlef+1,num));

    int cost=2;
    if(N-1-uplef<=dwlef) cost=1;
    if(N-1-dwlef<=uplef) cost=1;
    if(S[uplef]==T[dwlef]) chmax(res,rec(uplef+1,dwlef+1,num)+cost);
    else if(num>0) chmax(res,rec(uplef+1,dwlef+1,num-1)+cost);

    return dp[uplef][dwlef][num]=res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin>>S;
  cin>>K;
  N=S.size();

  T=S;
  reverse(T.begin(),T.end());
  rep(i,N+1) rep(j,26) nxt[i][j]=N;
  for(int i=N-1;i>=0;i--){
      for(int j=0;j<26;j++){
          nxt[i][j]=nxt[i+1][j];
      }
      nxt[i][T[i]-'a']=i;
  }

  cout<<rec(0,0,K)<<endl;

  return 0;
}
