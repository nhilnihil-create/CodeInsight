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
  int n;
  cin >> n;
  if(n == 0){
    cout << 0 << endl;
    return 0;
  }
  stack<int> ans;
  while(n != 0){
    if(abs(n) % 2 == 0) ans.push(0);
    else{
      n--;
      ans.push(1);
    }
    n /= -2;
  }
  while(!ans.empty()){
    cout << ans.top();
    ans.pop();
  }
  cout << endl;
  return 0;
}