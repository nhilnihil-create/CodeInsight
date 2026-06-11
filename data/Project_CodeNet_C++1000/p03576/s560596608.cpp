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
int main() {
  int n,K; cin >> n >> K;
  vector<int> x(n),y(n);
  rep(i,n) cin >> x[i] >> y[i];
  
  ll ans = 1LL << 62;
  
  rep(i,n)rep(j,n)rep(k,n)rep(l,n){
    int cnt = 0;
    if(x[i] < x[j] && y[k] < y[l]){
      rep(m,n){
        if(x[i] <= x[m] && x[j] >= x[m] && y[k] <= y[m] && y[l] >= y[m]) cnt++;
      }
    }
    if(cnt >= K) chmin(ans, (ll)(x[j]-x[i])*(ll)(y[l]-y[k]));
  }
  
  cout << ans;
  return 0;
}