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

int main()
{
  int n, m;
  cin >> n >> m;
  int x[n][m];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      char c;
      cin >> c;
      if(c=='#') x[i][j] = -1;
      else x[i][j] = 0;
    }
  }
  x[0][0] = 1;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(x[i][j]==-1) continue;
      if(i-1>=0 && x[i-1][j]!=-1) x[i][j] = (x[i][j] + x[i-1][j])%mod;
      if(j-1>=0 && x[i][j-1]!=-1) x[i][j] = (x[i][j] + x[i][j-1])%mod;
    }
  }

  cout << x[n-1][m-1] << "\n";

  return 0;
}