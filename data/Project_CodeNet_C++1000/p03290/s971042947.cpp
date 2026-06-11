#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;

int main(){
  int D, G;  cin >> D >> G;
  vector<int> p(D), c(D);
  rep(i,D) cin >> p[i] >> c[i];
  int ans = 1e5;
  rep(x,1<<D){
    int s=0, num=0,  mn=0;
    rep(i,D){
      if(x>>i&1){
        s += 100*(i+1)*p[i]+c[i];
        num += p[i];
      }else
        mn = i;
    }
    if(s<G){
      rep(i,p[mn]){
        s+=100*(mn+1);
        num++;
        if(s>=G) break;
      }
    }
    if(s<G) continue;
    ans = min(ans, num);
  }
  cout << ans << endl;
  return 0;
}