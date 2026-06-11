#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = -1e18;

signed main(){
  lint N, M; cin >> N >> M;
  vector<lint> x(N), y(N), z(N);
  for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> z[i];
  lint ans = INF;
  for(lint bit = 0; bit < (1 << 3); bit++){
    vector<lint> data(N, 0);
    if(bit & (1 << 0)) for(lint i = 0; i < N; i++) data[i] += x[i];
    else for(lint i = 0; i < N; i++) data[i] -= x[i];
    if(bit & (1 << 1)) for(lint i = 0; i < N; i++) data[i] += y[i];
    else for(lint i = 0; i < N; i++) data[i] -= y[i];
    if(bit & (1 << 2)) for(lint i = 0; i < N; i++) data[i] += z[i];
    else for(lint i = 0; i < N; i++) data[i] -= z[i];
    sort(data.begin(), data.end(), greater<lint>());
    lint ans1 = 0;
    for(lint i = 0; i < M; i++) ans1 += data[i];
    ans = max(ans, ans1);
  }
  cout << ans << endl;
}