//実装できなくて答え見た
//きれいなコード
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
const ll MOD = 1000000007;
// const ll INF = 1000000000000000000LL;

int main() {
  int n;
  cin >> n;
  int table[n-1][3];
  rep(i,n-1){
    rep(j,3){
      cin >> table[i][j];
    }
  }
  vector<int> ans(n);
  rep(i,n-1){
    int now=table[i][1]+table[i][0];
    for(int j=i+1;j<n-1;j++){
      if(table[j][1]>=now)
        now=table[j][1];
      else{
        int a=table[j][1];
        while(1){
          a+=table[j][2];
          if(now<=a){
            now=a;
            break;
          }
        }
      }
      now+=table[j][0];
    }
    ans[i]=now;
  }
  rep(i,n)
    cout << ans[i] << endl;
  return 0;
}