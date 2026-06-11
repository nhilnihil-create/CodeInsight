#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int dp[500][500];

int main()
{
  cout << fixed << setprecision(10);
  int H,W;
  cin >> H >> W;
  vector<vector<int>> c(10,vector<int>(10));
  vector<vector<int>> A(H,vector<int>(W));
  rep(i,10)
  {
    rep(j,10)
    {
      cin >> c[i][j];
    }
  }
  rep(i,H)
  {
    rep(j,W)
    {
      cin >> A[i][j];
    }
  }
  for(int k=0;k<10;k++)
  {
    for(int i=0;i<10;i++)
    {
      for(int j=0;j<10;j++)
      {
        c[i][j] = min(c[i][j],c[i][k]+c[k][j]);
      }
    }
  }
  int sum = 0;
  rep(i,H)
  {
    rep(j,W)
    {
      if(A[i][j]==-1||A[i][j]==1)
      {
        continue;
      }
      else
      {
        sum += c[A[i][j]][1];
      }
      
    }
  }
  cout << sum << endl;
  return 0;
}
