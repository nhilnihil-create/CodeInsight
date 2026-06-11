#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef long int li;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef pair<ll, ll>P;
typedef tuple<ll,int,int,int,int,int,int,int>T;
#define PI 3.14159265358979
const int MAX = 510000;
const int MOD = 1000000007;
//この設定だとn<10^7が限界。maxの0を一個増やせば100msかかるが一桁増やせる。
long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main(){
  int N;
  cin>>N;
  priority_queue<P,vector<P>,greater<P>>Blue;
  priority_queue<P,vector<P>,greater<P>>Red;
  //Red入力
  rep(i,N){
    int a,b;
    cin>>a>>b;
    Red.push(P(a,b));
  }
  //Blue
  rep(i,N){
    int a,b;
    cin>>a>>b;
    Blue.push(P(a,b));
  }
  ll ans=0;
  priority_queue<P>yred;
  rep(i,N){
    auto bl=Blue.top();Blue.pop();
    int flag=0;
    while(flag==0){
      if(Red.empty()){break;}
      auto re=Red.top();
      if(re.first<bl.first){
        Red.pop();
        //yで並べるため入れ替え
        auto g=P(re.second,re.first);
        yred.push(g);
      }
      else{break;}
    }
    queue<P>memo;
    while(!yred.empty()){
      auto t=yred.top();
      if(t.second<bl.first&&t.first<bl.second){
        yred.pop();ans++;
       break;
      }
      else{memo.push(t);yred.pop();}
    }
    while(!memo.empty()){
      auto t=memo.front();memo.pop();
      yred.push(t);
    }
  }
  cout<<ans;
} 
