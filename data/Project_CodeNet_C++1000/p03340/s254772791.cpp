#include <bits/stdc++.h>
using namespace std;
const int64_t MAXN = 200010;
int64_t S[MAXN][20]; // Aのi番目までの、j桁目(2進数)の和

int main()
{
  int64_t N, a, j, ans = 0, prev = -1;
  cin >> N;
  vector<pair<int64_t, int64_t>> A;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    if (i >= 1 && a == 0)
    {
      if (prev == 0)
        A.at(A.size() - 1).second++;
      else
        A.push_back({0, 1});
    }
    else
    {
      A.push_back({a, 1});
    }
    prev = a;
  }
  int64_t n = A.size();
  for (int i = 0; i < n; i++)
  {
    a = A.at(i).first, j = 0;
    for (int j = 0; j < 20; j++)
    {
      S[i + 1][j] = S[i][j] + (a % 2);
      a /= 2;
    }
  }
  for (int l = 1; l <= n; l++)
  {
    bool ok = 1;
    for (int r = l; r <= n; r++)
    {
      for (int j = 0; j < 20; j++)
      {
        if (S[r][j] - S[l - 1][j] > 1)
        {
          ok = 0;
          break;
        }
      }
      if (ok)
      {
        if (A.at(l - 1).first == 0 && A.at(r - 1).first == 0)
        {
          int64_t lz = A.at(l - 1).second, rz = A.at(r - 1).second;
          if (l == r)
          {
            ans += lz * (lz + 1) / 2;
          }
          else
          {
            ans += lz * rz;
          }
        }
        else if (A.at(l - 1).first == 0)
        {
          ans += A.at(l - 1).second;
        }
        else if (A.at(r - 1).first == 0)
        {
          ans += A.at(r - 1).second;
        }
        else
        {
          ans++;
        }
      }
      else
      {
        break;
      }
    }
  }
  cout << ans << endl;
}
