#include<iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define ll long long
#define rep(i,n) for (ll i = 0; i < (n); ++i)

using namespace std;

int main(){
  ll D, G, count, point, ans = 1010, l, rem;

  cin >> D >> G;

  vector<ll> p(D), c(D);

  rep(i, D){
    cin >> p[i] >> c[i];
  }

  rep(i, (1<<D)){
    count = 0; point = 0; l = -1;
    rep(j, D){
      if ((i&(1<<j)) != 0) {
        count += p[j];
        if(count >= ans) break;
        point += p[j]*(j+1)*100 + c[j];
      }else{
        l = j+1; //完答していない中で一番配点高いのがl*100点問題
      }
    }
    if(count >= ans) continue;
    if(point < G && l != -1){
      rem = (G-point-1)/(l*100) +1;
      if(p[l-1] <= rem) continue;
      count += rem;
    }
    if(point < G && l == -1) continue;
    ans = min(ans, count);
  }

  cout << ans << endl;




  return 0;
}
