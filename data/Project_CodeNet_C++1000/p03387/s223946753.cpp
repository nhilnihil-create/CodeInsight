#include <bits/stdc++.h>
using namespace std;
int a, b, c, even = 0, mx = 0, ans = 0;
int main(){
  cin >> a >> b >> c;
  vector<int> N{a, b, c};
  for(int i=0; i<3; ++i) if(N[i]%2 == 0) ++even;
  if(even == 2){
    for(int i=0; i<3; ++i) if(N[i]%2 == 0) ++N[i];
    ++ans;
  }else if(even == 1){
    for(int i=0; i<3; ++i) if(N[i]%2 != 0) ++N[i];
    ++ans;
  }
  for(int i=0; i<3; ++i) mx = max(mx, N[i]);
  for(int i=0; i<3; ++i) if(N[i] < mx) ans += (mx-N[i])/2;
  cout << ans << endl;
}