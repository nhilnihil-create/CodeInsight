#include<bits/stdc++.h>
using namespace std;
int n;
double dp[301][301][301]={}; //dp[3個ある皿][2個ある皿][1個ある皿] -> すべて空になるまでの期待値
/*
dp[i][j][k]からの遷移
->dp[i][j][k]     確率(n-(i+j+k))/n = p1
->dp[i][j][k-1]   確率k/n = p2
->dp[i][j-1][k+1] 確率j/n = p3
->dp[i-1][j+1][k] 確率i/n = p4
これらの状態に遷移するために1手必要なので +1 をする
dp[i][j][k] = 1 + dp[i][j][k]*p1 + dp[i][j][k-1]*p2 + dp[i][j-1][k+1]*p3 + dp[i-1][j+1][k]*p4
dp[i][j][k]が両辺にあるので移項をする
1-p1 = 1-(n-(i+j+k))/n = (i+j+k)/n = p5
dp[i][j][k]*p5 = 1 + dp[i][j][k-1]*p2 + dp[i][j-1][k+1]*p3 + dp[i-1][j+1][k]*p4
dp[i][j][k] = (1 + dp[i][j][k-1]*p2 + dp[i][j-1][k+1]*p3 + dp[i-1][j+1][k]*p4)/p5
            = (n + dp[i][j][k-1]*k + dp[i][j-1][k+1]*j + dp[i-1][j+1][k]*i)/(i+j+k)
初期条件 dp[i][j][k]=0
*/
double solve(int i, int j, int k){
  if(dp[i][j][k]>-1) return dp[i][j][k];
  double p=n;
  if(k>0) p += solve(i,j,k-1) * k;
  if(j>0) p += solve(i,j-1,k+1) * j;
  if(i>0) p += solve(i-1,j+1,k) * i;
  p /= (i+j+k);
  dp[i][j][k] = p;
  return p;
}
int main(){
  cin >> n;
  vector<int> num(4,0);
  for(int i=0;i<n;i++){
    int a;
    cin >> a;
    num[a]++;
  }
  for(int i=0;i<301;i++)for(int j=0;j<301;j++)for(int k=0;k<301;k++) dp[i][j][k]=-1;
  dp[0][0][0]=0; //初期条件
  cout << fixed << setprecision(12) << solve(num[3],num[2],num[1]) << endl;                                             
}