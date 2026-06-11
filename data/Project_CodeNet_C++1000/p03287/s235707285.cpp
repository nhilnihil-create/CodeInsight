#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int INF = 1e9;

signed main(){
  lint N, M; cin >> N >> M;
  vector<lint> a(N);
  for(int i = 0; i < N; i++) cin >> a[i];
  map<lint, lint> MAP;
  lint num = 0;
  MAP[0]++;
  for(int i = 0; i < N; i++){
    num += a[i]; num %= M;
    MAP[num]++;
  }
  lint ans = 0;
  for(auto value : MAP) ans += value.second * (value.second - 1) / 2;
  cout << ans << endl;
}