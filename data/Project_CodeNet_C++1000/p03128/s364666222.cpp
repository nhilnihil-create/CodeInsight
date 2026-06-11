#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}

const string MINUSINF = "-";
int match[10] = {2,5,5,4,5,6,3,7,6};
string dp[11000];

void chmax(string& a, string b){
  if(a.size() < b.size()) a = b;
  else if(a.size() == b.size()){
    if(a<b) a = b;
  }
}

int main(){
  int n,m; cin >> n >> m;
  vector<int> a(m);
  rep(i,m) cin >> a[i];
  
  rep(i,11000) dp[i] = MINUSINF;
  dp[0] = "";
  
  for(int i = 0; i <= n; i++){
    if(dp[i] == MINUSINF) continue;
    rep(j,m){
      chmax(dp[i+match[a[j]-1]],dp[i]+(char)('0'+a[j]));  
    }
  }
  
  cout << dp[n] << endl;
  
  return 0;
}