#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  string s;
  cin >> s;
  if(s.size() == 1){
    cout << s << endl;
    return 0;
  }
  int c0 = 0, c9 = 0;
  rep(i, s.size()){
    if(s.at(i) == '0') c0++;
    if(s.at(i) == '9') c9++;
  }
  if(s.size()-1 == c0){
    int ans = s.front() - '0' - 1;
    ans += c0*9;
    cout << ans << endl;
    return 0;
  }
  if(c9 == s.size()){
    int ans = 9 * s.size();
    cout << ans << endl;
    return 0;
  }
  if(c9 == s.size()-1 && s.front() != '9'){
    int ans = c9 * 9 + (s.front() - '0');
    cout << ans << endl;
    return 0;
  }
  int ans = 9*(s.size()-1) + (s.front() - '0' - 1);
  cout << ans << endl;

  return 0;
}