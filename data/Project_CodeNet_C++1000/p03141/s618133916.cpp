#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<lint> a(N), b(N), c(N);
  lint ans = 0;
  for(lint i = 0; i < N; i++){
    cin >> a[i] >> b[i];
    c[i] = a[i] + b[i];
    ans -= b[i];
  }
  sort(c.begin(), c.end()); reverse(c.begin(), c.end());
  for(lint i = 0; i < N; i += 2) ans += c[i];
  cout << ans << endl;
}