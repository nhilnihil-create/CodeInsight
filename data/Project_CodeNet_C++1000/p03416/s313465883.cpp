#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main()
{
  int a, b;
  cin >> a >> b;
  int cnt = 0;
  for (int i = a; i <= b; i++)
  {
    int j1, j2, j3, j4;
    j1 = i / 10000;
    j2 = (i - j1 * 10000) / 1000;
    j3 = (i % 100) / 10;
    j4 = i % 10;
    if (j4 == j1 && j2 == j3)
    {
      cnt++;
    }
  }
  cout << cnt << endl;
}
