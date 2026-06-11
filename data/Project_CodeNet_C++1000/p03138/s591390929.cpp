#include <bits/stdc++.h>
#define FOR(i, k, n) for(int i = (k); i < (n); i++)
#define FORe(i, k, n) for(int i = (k); i <= (n); i++)
#define FORr(i, k, n) for(int i = (k)-1; i > (n); i--)
#define FORre(i, k, n) for(int i = (k)-1; i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPr(i, n) FORre(i, n, 0)
#define ALL(x) (x).begin(), (x).end()
#define ALLr(x) (x).rbegin(), (x).rend()
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using ll = long long;

const int INF = 1001001001;

ll dp[41][2];
//[i][0]:i桁目がkと同じ
//[i][1]:i桁目がk以下なのが確定

int main(void){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  REP(i, n) cin >> a[i];
  REP(i, 41){
    dp[i][0] = -1;
    dp[i][1] = -1;
  }

  dp[40][0] = 0;
  
  FORre(i, 40, 0){
    ll m = 1ll << i;
    ll num = 0;
    REP(j, n) if(a[j]&m) num++;

    //0:1の数, 1:1が反転するので0の数
    ll s[] = {m*num, m*(n-num)};

    //1->1
    if(dp[i+1][1] != -1){
      chmax(dp[i][1], max(dp[i+1][1]+s[0], dp[i+1][1]+s[1]));
    }

    if(dp[i+1][0] != -1){
      //iビット目が1
      if(k&m){
        //0にする場合k以下が確定
        chmax(dp[i][1], dp[i+1][0]+s[0]);
        //1なら同じまま
        chmax(dp[i][0], dp[i+1][0]+s[1]);
      }else{
        //0の場合のみ
        chmax(dp[i][0], dp[i+1][0]+s[0]);
      }
    }
  }
  
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}