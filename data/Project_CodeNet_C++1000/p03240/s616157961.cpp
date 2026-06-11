#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int i, j, k;
  ll N, H, hight, count=0;
  bool judge;
  
  cin >> N;
  
  vector<ll> x(N);
  vector<ll> y(N);
  vector<ll> h(N);
  
  rep(i,N) cin >> x[i] >> y[i] >> h[i];
  
  rep(i,101){
    rep(j,101){
      judge = true;
      rep(k,N){
        if(h[k]!=0){
          H=llabs(x[k]-i)+llabs(y[k]-j)+h[k];
          break;
        }
      }
      rep(k,N){
        hight=H-llabs(i-x[k])-llabs(j-y[k]);
        if(h[k]!=max((ll)0,hight)){
          judge = false;
          break;
        }
      }
      if(judge==true){
        cout << i << " " << j << " " << H;
        return 0;
      }
    }
  }
}