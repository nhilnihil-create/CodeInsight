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
  
  ll dp[11][10][10];
  
  
  for (int i = 0; i < 11; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        dp[i][j][k] = INF;
      }
    }
  }
  
  for (int j = 0; j < 10; j++) {
    for (int k = 0; k < 10; k++) {
      dp[1][j][k] = cost[j][k];
    }
  }
  
  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        for (int l = 0; l < 10; l++) {
          chmin(dp[i+1][j][k], dp[i][j][l] + cost[l][k]);
          chmin(dp[i+1][j][k], dp[i][j][k]);
        }
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
    ans += numcount[i] * dp[10][i][1];
  }
  
  cout << ans << endl;
  
  
  
}