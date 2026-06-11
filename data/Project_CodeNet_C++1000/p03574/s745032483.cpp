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
vector<char> C = {'0','1','2','3','4','5','6','7','8'};

int main()
{
  cout << fixed << setprecision(10);
  int H,W;
  cin >> H >> W;
  vector<vector<char>> S(H,vector<char>(W));
  int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
  int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
  rep(i,H)
  {
    rep(j,W)
    {
      cin >> S[i][j];
    }
  }
  rep(i,H)
  {
    rep(j,W)
    {
      if(S[i][j]=='#') continue;
      int b = 0;
      rep(k,8)
      {
        if(i+dx[k]<0||i+dx[k]>H-1) continue;
        if(j+dy[k]<0||j+dy[k]>W-1) continue;
        if(S[i+dx[k]][j+dy[k]]=='#') b ++;
      }
      S[i][j] = C[b];
    }
  }
  rep(i,H)
  {
    rep(j,W)
    {
      cout << S[i][j];
      if(j==W-1) cout << endl;
    }
  }
  return 0;
}