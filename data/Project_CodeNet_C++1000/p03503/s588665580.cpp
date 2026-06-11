#include<bits/stdc++.h>
using namespace std;
using lint = long long;

signed main(){
  lint N; cin >> N;
  vector<vector<lint> > open(N, vector<lint> (10));
  for(lint i = 0; i < N; i++){
    for(lint j = 0; j < 10; j++) cin >> open[i][j];
  }
  vector<vector<lint> > profit(N, vector<lint> (11));
  for(lint i = 0; i < N; i++){
    for(lint j = 0; j < 11; j++) cin >> profit[i][j];
  }
  lint ans = -1e18;
  for(lint bit = 1; bit < (1 << 10); bit++){
    lint ans1 = 0;
    for(lint j = 0; j < N; j++){
      lint counter = 0;
      for(lint k = 0; k < 10; k++){
        if((bit & (1 << k)) && open[j][k]) counter++;
      }
      ans1 += profit[j][counter];
    }
    ans = max(ans, ans1);
  }
  cout << ans << endl;
}
