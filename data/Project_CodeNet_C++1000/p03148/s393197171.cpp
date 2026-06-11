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

int main(){
  int n,k; cin >> n >> k;
  
  priority_queue<int> kind[n];
  rep(i,n){
    int t,d; cin >> t >> d;
    kind[t-1].push(d);
  }
  
  priority_queue<int> best,remain;
  
  rep(i,n){
    if(!kind[i].empty()){
      best.push(kind[i].top());
      kind[i].pop();
      while(!kind[i].empty()){
        remain.push(kind[i].top());
        kind[i].pop();
      }
    }
  }
  
  vector<ll> bsum = {0};
  vector<ll> rsum = {0};
  
  while(!best.empty()){
    bsum.push_back(bsum.back()+best.top());
    best.pop();
  }
  while(!remain.empty()){
    rsum.push_back(rsum.back()+remain.top());
    remain.pop();
  }
  
  ll ans = 0;
  for(ll x = 1; x <= k;x++){
    if(x >= bsum.size()) break;
    if(k-x >= rsum.size()) continue;
    ans = max(ans,bsum[x]+rsum[k-x]+x*x);
  }
  
  cout << ans << endl;
  
  return 0;
}