#include<bits/stdc++.h>
using namespace std;
int n;
const long long INF = 1e15;
long long a[405], cost[405];
long long dp[405][405]; //[l, r]のスライムを1体にするのに必要なコスト
void calccost(){
  cost[0] = 0;
  for(int i=0; i<n; i++) cost[i+1] = cost[i] + a[i];
}
long long solve(int l, int r){
  if(l == r) return 0;
  if(dp[l][r] == INF) for(int i=l; i<r; i++) dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + cost[r+1] - cost[l]);
  return dp[l][r];
}
int main(){
  cin >> n;
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) dp[i][j] = INF;
  calccost();
  cout << solve(0, n-1) << endl;
}