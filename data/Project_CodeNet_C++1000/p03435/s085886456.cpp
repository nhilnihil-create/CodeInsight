#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)

int main()
{
  int x[3][3];
  rep(i,3)
  {
    rep(j,3) cin >> x[i][j];
  }
  
  int a[3],b[3];
  for(int i = 0; i <= x[0][0]; i++)
  {
    b[0] = x[0][0] - i;
    b[1] = x[0][1] - i;
    b[2] = x[0][2] - i;
    
    if( x[1][0] - b[0] != x[1][1] - b[1] || x[1][0] - b[0] != x[1][2] - b[2] )
    {
      continue;
    }
    if( x[2][0] - b[0] != x[2][1] - b[1] || x[2][0] - b[0] != x[2][2] - b[2] )
    {
      continue;
    }
    
    cout << "Yes" << endl;
    return 0;
  }
  
  cout << "No" << endl;
    
}