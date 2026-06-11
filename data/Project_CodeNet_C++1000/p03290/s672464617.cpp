#include<bits/stdc++.h>
using namespace std;
using ll=long long;



int main(){
  int d,g;
  cin >> d >> g;
  vector<int> p(d),c(d);
  for(int i=0;i<d;++i) cin >> p[i] >> c[i];


  ll ans=1000000000000000;
  for(int bit=0;bit<(1<<d);++bit){
    ll sum=0;
    ll num=0;
    for(int i=0;i<d;++i){
      if(bit & (1<<i)){
        sum+=c[i]+p[i]*100*(i+1);
        num+=p[i];
      }
    }
    if(sum>=g) ans=min(ans,num);
    else{
      for(int i=d-1;i>=0;--i){
        if(bit & (1<<i)) continue;
        for(int j=0;j<p[i];++j){
          if(sum>=g) break;
          sum+=100*(i+1);
          ++num;
        }
      }
      ans=min(ans,num);
    }
  }

  cout << ans << endl;
  return 0;
}
