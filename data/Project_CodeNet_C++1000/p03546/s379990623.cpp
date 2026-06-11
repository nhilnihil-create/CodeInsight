#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int H,W;
  cin >> H >> W;
  ll dp[10][10];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      cin >> dp[i][j];
    }
  }

  for(int k = 0; k < 10; k++){
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < 10; j++){
        dp[i][j] = min(dp[i][j], dp[i][k]+ dp[k][j]);
      }
    }
  }

  ll cost = 0;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      int tmp;
      cin >> tmp;
      if(tmp == -1) continue;

      cost += dp[tmp][1];
    }
  }
  cout << cost << endl;

}
