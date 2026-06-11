#include <bits/stdc++.h>
using namespace std;

const int maxn = 305;

double dp[maxn][maxn][maxn];

int main()
{

  int n;
  cin >> n;
  int cnt1 = 0, cnt2 = 0, cnt3 = 0;
  for(int i = 0; i < n ; i++)
  {
    int a;
    cin >> a;
    if(a == 1)
      cnt1++;
    else if(a == 2)
      cnt2++;
    else
      cnt3++;
  }

  for(int c = 0; c <= n; c++)
  {
    for(int b = 0; b <= n; b++)
    {
      for(int a = 0; a <= n; a++)
      {
        int k = a + b + c;
        if(k == 0)
          continue;
        if(k > n)
          continue;
        dp[a][b][c] += (1.0 * n)/k;
        if(a)
          dp[a][b][c] += (1.0 * a)/k * dp[a - 1][b][c];
        if(b)
          dp[a][b][c] += (1.0 * b)/k * dp[a + 1][b - 1][c];
        if(c)
          dp[a][b][c] += (1.0 * c)/k * dp[a][b + 1][c - 1]; 
      }
    }
  }

  cout<< fixed << setprecision(10) << dp[cnt1][cnt2][cnt3] << endl;
  return 0;
}