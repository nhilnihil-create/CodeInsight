#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int INF = 1000000;

void chmin(ll& a, ll b){ 
  if (a > b) a = b;
}

int main() {
  int H, W;
  cin >> H >> W;
  
  ll cost[10][10];
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> cost[i][j];
    }
  }
  
  ll dp[10][10];
  
  
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      dp[i][j] = cost[i][j];
    }
  }

  
  for (int k = 0; k < 10; k++) {
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        chmin(dp[i][j], dp[i][k] + dp[k][j]);
      }
    }
  }
  
  
  
  vector<ll> numcount(10, 0);
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int x;
      cin >> x;      
      if (x != -1) numcount[x]++;
    }
  }
  
  
  ll ans = 0;
  for (int i = 0; i < 10; i++) {
    ans += numcount[i] * dp[i][1];
  }
  
  cout << ans << endl;
  
  
  
}