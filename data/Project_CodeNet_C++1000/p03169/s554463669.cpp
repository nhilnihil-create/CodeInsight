#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
  if(a < b) {
    a= b;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &a, T b) {
  if(a > b) {
    a= b;
    return 1;
  }
  return 0;
}
ll mod= 1e9 + 7;

double dp[310][310][310];
int n;

double rec(int a, int b, int c) {
  if(dp[a][b][c] >=0) return dp[a][b][c];
  if(a == 0 && b == 0 && c == 0) return 0.0;
  double res= 0.0;
  if(a > 0) res+= rec(a - 1, b, c) * a;
  if(b > 0) res+= rec(a + 1, b - 1, c) * b;
  if(c > 0) res+= rec(a, b + 1, c - 1) * c;
  res+= n;
  res*= 1.0 / (a + b + c);

  return dp[a][b][c]= res;
}

int main() {
  cin >> n;
  int v[3]= {};
  rep(i, n) {
    int g;
    cin >> g;
    v[g - 1]++;
  }

  memset(dp, -1, sizeof(dp));
  printf("%.12lf\n",rec(v[0],v[1],v[2]));
}
