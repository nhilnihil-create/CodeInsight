#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>d(n);
  vector<bool>p(25);
  p[0] = p[24] = 1;
  rep(i,0,n) cin >> d[i];
  sort(d.begin(),d.end());
  rep(i,0,n){
    if(i%2 == 0){
      if(p[d[i]]){
        if(p[24-d[i]]){
          cout << 0 << endl;
          return 0;
        }
        p[24-d[i]] = 1;
      }
      else p[d[i]] = 1;
    }
    else{
      if(p[24-d[i]]){
        if(p[d[i]]){
          cout << 0 << endl;
          return 0;
        }
        p[d[i]] = 1;
      }
      else p[24-d[i]] = 1;
    }
  }
  int ans = 24,m = 0;
  rep(i,1,25){
    if(p[i]){
      ans = min(ans,i-m);
      m = i;
    }
  }
  cout << ans << endl;
}