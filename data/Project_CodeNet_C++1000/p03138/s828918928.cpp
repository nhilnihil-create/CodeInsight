#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//i=桁数
//j=未満フラグ
ll dp[65][2];

int main(){
  int n; ll k;
  cin>>n>>k;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];

  //DP初期化
  rep(i,65)rep(j,2)dp[i][j]=-1;
  dp[0][0]=0;

  //桁DP
  for(int i=0; i<60; ++i){
    for(int j=0; j<2; ++j)if(dp[i][j]>=0){

      //見てるbit
      int d=60-1-i;
      ll msk=1LL<<d;

      //そのbitの0,1の数
      int zero=0,one=0;
      rep(i,n){
        if(a[i]&msk)one++;
        else zero++;
      }

      //kのi桁目が1のとき、i桁目を0にしたら未満フラグ成立
      int j2=j;
      if(k&msk)j2=1;

      //そのbitを0にするとき
      chmax(dp[i+1][j2],dp[i][j]+one*msk);

      //そのbitを1にするとき(未満フラグが立っている or kのi桁目が1)
      if((k&msk)||j==1){
        chmax(dp[i+1][j],dp[i][j]+zero*msk);
      }
    }
  }
  //未満フラグ立ってる方と立ってない方のmaxを取る
  cout<<max(dp[60][0],dp[60][1])<<endl;
}