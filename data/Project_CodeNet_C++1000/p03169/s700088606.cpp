#include<bits/stdc++.h>
using namespace std;
int N;
double dp[301][301][301];
double make_dp(int i, int j, int k){
  if (dp[i][j][k] >= 0){
    return dp[i][j][k];
  }
  if (i == 0 && j == 0 && k == 0){
    return 0.0;
  }
  double y = 0.0;
  if (i > 0){
    y += make_dp(i-1, j, k) * i;
  }
  if (j > 0){
    y += make_dp(i+1, j-1, k) * j;
  }
  if (k > 0){
    y += make_dp(i, j+1, k-1) * k;
  }
  y += N;
  y *= 1.0 / (i + j + k);
  dp[i][j][k] = y;
  return dp[i][j][k];
}
int main(){
  cin >> N;
  int SUSY[3] = {0, 0, 0};
  int tmp;
  for (int i=0;i<N;i++){
    cin >> tmp;
    SUSY[tmp-1] += 1;
  }
  for (int i=0;i<=N;i++){
    for (int j=0;j<=N;j++){
      for (int k=0;k<=N;k++){
        dp[i][j][k] = -1.0;
      }
    }
  }
  printf("%.012f", make_dp(SUSY[0], SUSY[1], SUSY[2]));
  return 0;
}