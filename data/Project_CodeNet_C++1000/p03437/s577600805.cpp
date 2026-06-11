#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 1;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  ll x,y;
  cin >> x >> y;
  if(x % y == 0){
    puts("-1");
    return 0;
  }
  rep(i,100000){
    if(x*i % y != 0){
      cout << x*i << endl;
      return 0;
    }
  }
  return 0;
}
