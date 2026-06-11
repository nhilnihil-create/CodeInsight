#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int N = 305;
double dp[N][N][N];
int n;

double rec(int i, int j, int k) {
  if (dp[i][j][k] != -1) return dp[i][j][k];
  if (i == 0 && j == 0 && k == 0) return dp[0][0][0] = 0;
  double res = n;
  if (i) res += i * rec(i-1, j+1, k);
  if (j) res += j * rec(i, j-1, k+1);
  if (k) res += k * rec(i, j, k-1);
  res /= i + j + k;
  return dp[i][j][k] = res; 
}

int main() {
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> cnt(4);
  rep(i, n) cnt[a[i]]++;
  rep(i, n+1) rep(j, n+1) rep(k, n+1) dp[i][j][k] = -1;
  double ans = rec(cnt[3], cnt[2], cnt[1]);
  printf("%.9f\n", ans);
  return 0;
}