#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,int>;
using T = tuple<string,int,int>;

int main(){
  int a,b,t; cin >> a >> b >> t;
  int now = a;
  int ans = 0;
  while(now <= t){
    now += a;
    ans += b;
  }
  cout << ans << endl;
  return 0;
}