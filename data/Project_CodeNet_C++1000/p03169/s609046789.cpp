#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int n, num[4];
double dp[310][310][310];

double dfs(int a, int b, int c) {
  if(a==0&&b==0&&c==0) return 0;
  if(dp[a][b][c]>=0) return dp[a][b][c];
  int sum = a + b + c;
  dp[a][b][c] = 1.0*n/sum;
  if(a>0) dp[a][b][c] += dfs(a-1,b,c)*a/sum;
  if(b>0) dp[a][b][c] += dfs(a+1,b-1,c)*b/sum;
  if(c>0) dp[a][b][c] += dfs(a,b+1,c-1)*c/sum;
  return dp[a][b][c];
}


int main() {
  memset(dp,-1,sizeof(dp));
  cin >> n;
  rep(i,n) {
    int x;  cin >> x;
    num[x]++;
  }
  printf("%.10f\n", dfs(num[1],num[2],num[3]));
  return 0;
}