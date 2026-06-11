#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;
int N[3], even = 0, mx = 0, ans = 0;
int main(){
  cin >> N[0] >> N[1] >> N[2];
  rep(i, 3) if(N[i]%2 == 0) ++even;
  if(even == 2){
    rep(i, 3) if(N[i]%2 == 0) ++N[i];
    ++ans;
  }else if(even == 1){
    rep(i, 3) if(N[i]%2 != 0) ++N[i];
    ++ans;
  }
  rep(i, 3) mx = max(mx, N[i]);
  rep(i, 3) if(N[i] < mx) ans += (mx-N[i])/2;
  cout << ans << endl;
}