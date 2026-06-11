#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int d,g,ans = 1e9+7;
  cin >> d >> g;
  vector<int>p(d),c(d);
  rep(i,0,d) cin >> p[i] >> c[i];
  for (int bit = 0; bit < (1<<d); ++bit){
    int sum = 0,cnt = 0;
    rep(i,0,d){
      if (bit&(1<<i)){
        sum += p[i]*(i+1)*100+c[i];
        cnt += p[i];
      }
    }
    if(sum < g){
      for(int i = d-1;i >= 0;i--){
        if(!(bit&(1<<i))){
          int t = (g-sum)/((i+1)*100);
          if((g-sum)%((i+1)*100) != 0) t++;
          if(t < p[i]){
            cnt += t;
            ans = min(ans,cnt);
          }
          break;
        }
      }
    }
    else ans = min(ans,cnt);
    //cout << ans << endl;
  }
  cout << ans << endl;
}