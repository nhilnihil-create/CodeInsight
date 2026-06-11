/* In the name of Allah */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define LL_INF 1LL << 62
#define INF 1 << 30
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 1000000007

string s, t;
int n, m;

int dp[3001][3001];
int x[3001][3001];

int solve(int p1, int p2){
  if(p1 >= n || p2 >= m) return 0;

  if(dp[p1][p2]!=-1) return dp[p1][p2];

  int res = 0;
  if(s[p1]==t[p2]){
    res = 1+solve(p1+1, p2+1);
    x[p1][p2] = 0;
  }
  int r = solve(p1, p2+1);
  if(r>res){
    res = r;
    x[p1][p2] = 1;
  }
  r = solve(p1+1, p2);
  if(r > res){
    res = r;
    x[p1][p2] = 2;
  }

  return dp[p1][p2] = res;
}

string ans = "";

void get_ans(int p1, int p2){
  if(p1>=n || p2>=m) return;
  if(s[p1]==t[p2]) ans += s[p1];
  if(x[p1][p2]==0) get_ans(p1+1, p2+1);
  if(x[p1][p2]==1) get_ans(p1, p2+1);
  if(x[p1][p2]==2) get_ans(p1+1, p2);
}

int main()
{
  memset(dp, -1, sizeof dp);
  cin >> s >> t;
  n = s.size();
  m = t.size();

  solve(0, 0);
  get_ans(0, 0);
  cout << ans << "\n";

  return 0;
}