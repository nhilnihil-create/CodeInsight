#include <bits/stdc++.h>
using namespace std;
using lint  = long long;

signed main(){
  lint N; cin >> N;
  string s; cin >> s;
  lint B = 0, W = 0;
  for(lint i = 0; i < N; i++){
    if(s[i] == '.') W++;
  }
  lint ans = W;
  for(lint i = 0; i < N; i++){
    lint ans1;
    if(s[i] == '#') B++;
    else W--;
    ans1 = W + B;
    ans = min(ans, ans1);
  }
  cout << ans << endl;
}