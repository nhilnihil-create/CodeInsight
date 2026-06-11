#include <bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N);
  lint sum = 0;
  map<lint, lint> MAP;
  MAP[0]++;
  for(lint i = 0; i < N; i++) cin >> a[i], sum += a[i], MAP[sum]++;
  lint ans = 0;
  for(auto value : MAP){
    ans += (value.second - 1) * value.second / 2;
  }
  cout << ans << endl;
}