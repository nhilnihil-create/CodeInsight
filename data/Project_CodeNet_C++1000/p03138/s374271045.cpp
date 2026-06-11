#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXV = 50;
ll dp[55][2];

int main() {
  ll n,k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(dp, -1, sizeof(dp));

  dp[0][0] = 0;
  for (int d = 0; d < MAXV; d++) {
    ll mask = 1LL << (MAXV - d - 1);

    int num = 0;
    for (int i = 0; i < n; i++) if(a[i] & mask) ++num;

    //xのd桁目を0,1にするときの数
    ll cost0 = mask * num;
    ll cost1 = mask * (n - num);

    //0:tight 1:loose
    //loose -> loose
    if(dp[d][1] != -1) {
      dp[d + 1][1] = max(dp[d + 1][1], dp[d][1] + (max(cost0, cost1)));
    }
    //tight -> tight
    if(dp[d][0] != -1) {
      if(k & mask) dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + cost1); //1が立ってる
      else dp[d + 1][0] = max(dp[d + 1][0], dp[d][0] + cost0);
    }

    //tight -> loose
    if(dp[d][0] != -1) {
      if(k & mask) dp[d + 1][1] = max(dp[d + 1][1], dp[d][0] + cost0);
    }
  }

  cout << max(dp[MAXV][0], dp[MAXV][1]) << endl;
}