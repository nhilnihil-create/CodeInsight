#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll n; cin>>n;
  vector<ll> capacity(6);
  for(int i=1; i<=5; i++) cin>>capacity[i];
  vector<ll> dp(7,0);
  ll minCapacity;
  for(int i=2; i<=6; i++) {
    // 最初の移動は、全員をキャパで割った回数かかる
    if(i==2) {
      dp[i] = ceil((double)n/capacity[i-1]);
      minCapacity = capacity[i-1];
    }
    else {
      // 前の交通機関より、次に使う交通機関のほうがキャパが大きいなら、最終グループはすぐ次に行ける
      if(capacity[i-1]>=minCapacity) dp[i] = dp[i-1]+1;
      else {
        // そうでないならば、1回目の移動と同じ計算をする
        dp[i] = (i-2)+ceil((double)n/capacity[i-1]);
        minCapacity = capacity[i-1];
      }
    }
  }
  cout << dp[6] << endl;
}
