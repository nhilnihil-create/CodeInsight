#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;

int main(){
  int d,g; cin >> d >> g; g /= 100;
  vector<int> p(d), c(d);
  rep(i,d){
    cin>>p[i]>>c[i];
    c[i] /= 100;
  }
  
  int ans = 1000;
  rep(i, (1<<d)){//コンプリートする問題の集合
    int point = 0;
    int num = 0;
    rep(j,d){
      if((i>>j)&1){
        point += c[j] + (j+1)*p[j];
        num += p[j];
      }
    }
    
    if(point >= g){
      ans = min(ans, num);
      continue;
    }
    
    for(int j=d-1; j>=0; j--){
      if((i>>j)&1)continue;
      int now = min(p[j]-1, (g-point+(j+1)-1)/(j+1));
      num += now;
      point += (j+1)*now;
      if(point>=g){
        ans = min(ans, num);
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}