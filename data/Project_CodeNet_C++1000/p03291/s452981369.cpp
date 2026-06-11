#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}

ll dp[100005][4];
const int MOD = 1e9+7;
int main(){
  string s; cin >> s;
  
  dp[0][0] = 1;
  rep(i,s.size()){
    rep(j,4){
      if(s[i] == '?'){
        dp[i+1][j] += dp[i][j]*3;
        dp[i+1][j] %= MOD;
      }else{
        dp[i+1][j] += dp[i][j];
        dp[i+1][j] %= MOD;
      }
    }
    if(s[i] == 'A' || s[i] == '?'){
      dp[i+1][1] += dp[i][0];
      dp[i+1][1] %= MOD;
    }
    if(s[i] == 'B' || s[i] == '?') {
      dp[i+1][2] += dp[i][1];
      dp[i+1][2] %= MOD;
    }
    if(s[i] == 'C' || s[i] == '?'){
      dp[i+1][3] += dp[i][2];
      dp[i+1][3] %= MOD;
    }
  }
  
  cout << dp[s.size()][3] << endl;
  
  return 0;
}