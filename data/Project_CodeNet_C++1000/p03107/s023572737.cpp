#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  stack<char> stk;
  string s;
  cin >> s;
  int ans = 0;
  rep(i, s.size()){
    char now = s.at(i);
    if(stk.empty() == false && stk.top() != now){
      stk.pop();
      ans += 2;
    }else{
      stk.push(now);
    }
  }
  cout << ans << endl;
  return 0;
}