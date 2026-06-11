#include <bits/stdc++.h>
// Hey! 僕の提出を見てくれてありがとう.
// ロボ子さん可愛いぞ！！！！！君もV沼にはまろう↓
// https://www.youtube.com/channel/UCDqI2jOz0weumE8s7paEk6g
using namespace std;
using ll = long long;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}//a,bの最大公約数(gcd)を求める
ll lcm(ll a,ll b){return abs(a*b)/gcd(a,b);}//a,bの最小公倍数(lcm)を求める
vector<ll> enum_div(ll n){vector<ll> ret;for(int i=1 ; i*i<=n ; i++){if(n%i == 0){ret.push_back(i);if(i!=1 && i*i!=n)ret.push_back(n/i);}}ret.push_back(n);return ret;}
//↑nの約数を求める
vector<bool> IsPrime; void sieve(size_t max){if(max+1 > IsPrime.size())IsPrime.resize(max+1,true);IsPrime[0] = false;IsPrime[1] = false;for(size_t i=2; i*i<=max; ++i)if(IsPrime[i])for(size_t j=2; i*j<=max; ++j)IsPrime[i*j] = false;}
//↑エラトステネスの篩で素数を求める
#define roundup(divisor,dividend) (divisor + (dividend - 1)) / dividend //切り上げ割り算
#define all(x) (x).begin(),(x).end() //xの初めから終わりまでのポインタ
#define size_t ll //size_tは自動でllに変換される
#define pb(x) push_back(x)
#define pri_queue priority_queue //優先度付きキュー
#define syo(x) fixed << setprecision(x) //iostreamで小数をx桁表示
//sortを降順にする時は greater<型>()

#define INF 10000000

int dx[4] = {1,0,-1,0} , dy[4] = {0,-1,0,1};
queue<tuple<int,int,int>> que;
vector<vector<int>> d(1010,vector<int>(1010));

int main(){
  int H,W;
  cin >> H >> W;  
  char c;
  for (int i = 0; i < H; i++) {
    for (int l = 0; l < W; l++) {
      cin >> c;
      d[i][l] = INF;
      if(c == '#'){
        que.emplace(i,l,0);
      }  
    }
  }


  ll ans = 0;
  ll x,y,t;

  while(que.size()){
    tie(y,x,t) = que.front(); que.pop();
    if(d[y][x] > t){
      d[y][x] = t;
      ans = max(ans,t);
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i] , ny = y + dy[i];
        if(0 <= nx && nx < W && 0 <= ny && ny < H)que.emplace(ny,nx,t+1);
      }
    }
  }

  cout << ans << endl;
}
