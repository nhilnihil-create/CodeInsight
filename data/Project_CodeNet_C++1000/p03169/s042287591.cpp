#include <bits/stdc++.h>
#define ll long long
using namespace std;

double dp[305][305][305];
int n;

double dfs(int a, int b, int c) {
  if(a+b+c==0) return 0.0;
  if(dp[a][b][c]>-0.5) return dp[a][b][c];
  double ks = (double) n/(a+b+c);
  double res = 0;
  if(a) {
    res += (dfs(a-1, b, c)+ks)*a/(a+b+c);
  }
  if(b) {
    res += (dfs(a+1, b-1, c)+ks)*b/(a+b+c);
  }
  if(c) {
    res += (dfs(a, b+1, c-1)+ks)*c/(a+b+c);
  }
  return dp[a][b][c]=res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  vector<int> a(4);
  cin >> n;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    a[x]++;
  }
  for(int i=0; i<=n; i++)
    for(int j=0; j<=n; j++)
      for(int k=0; k<=n; k++)
        dp[i][j][k] = -1;

  printf("%.12f\n", dfs(a[1], a[2], a[3]));

  
  return 0;
}