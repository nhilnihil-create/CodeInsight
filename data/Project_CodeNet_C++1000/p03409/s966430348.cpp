#include <bits/stdc++.h> //C++の標準ライブラリを一行で一括でインクルードする
#include <math.h> //数学関数と数学定数を利用する
#define rep(i,n) for (int i = 0; i < (n); i++)
#define PI 3.141592653589793
using namespace std;
typedef long long ll;
template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}
int gcd(int a, int b){//ユークリッドの互除法
  if (a < b) gcd(b,a); //aの方がbよりでかいのが前提
  if (b == 0) return a; //aをbで割り切れたらreturn
  else gcd(b, a % b);
}
const int INF = 1<<30;
const int MOD = 1000000007;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
  int n; cin >> n;
  vector<pair<int,int>> red(n),blue(n);
  vector<bool> use(n,true);
  rep(i,n){
    int x,y; cin >> x >> y;
    red[i] = {y,x};
  }
  rep(i,n){
    int x,y; cin >> x >> y;
    blue[i] = {x,y}; //逆にしているの注意
  }
  sort(red.begin(),red.end(),greater<pair<int,int>>());
  sort(blue.begin(),blue.end());
  int cnt = 0;
  rep(i,n){
    int bx = blue[i].first; int by = blue[i].second;
    rep(j,n){
      if(!use[j]) continue;
      int rx = red[j].second; int ry = red[j].first;
      if(rx >= bx) continue;
      if(ry < by){
        cnt++;
        use[j] = false;
        break;
      }
    }
  }
  
  cout << cnt << endl;
  
  return 0;
}