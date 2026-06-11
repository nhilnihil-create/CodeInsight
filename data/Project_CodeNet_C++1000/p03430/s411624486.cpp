#include <bits/stdc++.h>
using namespace std;

/*
変更箇所は順読み逆読みの少なくとも片方で役立たないといけない
つまり1点分として加算される必要がある
逆に1点分以上の役割は持てない<-嘘だった
例えば右端の文字が他に存在しない文字ならそれを変更するのはOK
*/
/*
問題概要は最長の回文を作れ？
だとすると中心決めてしまえばそこからは書き換えるかどうかは片側だけに注目すればよくて
sBtに対してsを右側から見ていくことを考える
変えるならt[now]しかありえなくて、書き換えた方がいいかどうかチェックするのに150^2かかる？
なんか違いそう
端から見て言ってdp[i][j][k]で考えるべき？
dp[i][j][k]:左からi文字右からj文字、k文字変更した時の最長回文
dp[i][j][k]=max(dp[i][j-1][k],dp[i-1][j][k],dp[i-1][j-1][k]+(s[i]==s[N-j-1]),dp[i-1][j-1][k-1]+1)
*/
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}
int dp[400][400][400];
signed main(){
  string s;int K;cin>>s>>K;
  int N=s.size();
  if(K>=N/2)fin(N);
  int ans=0;
  for(int k=0;k<=K;k++){
    for(int i=1;i<N;i++){
      for(int j=1;i+j<=N;j++){
        dp[i][j][k]=max({dp[i][j-1][k],dp[i-1][j][k],dp[i-1][j-1][k]+2*(s[i-1]==s[N-j])});
        if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k-1]+2);
        ans=max(ans,dp[i][j][k]+(i+j<N));
      }
    }
  }
  cout<<max(ans,1)<<endl;
}
