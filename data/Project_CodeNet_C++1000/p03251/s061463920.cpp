#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++)
  {
    int X;
    cin >> X;
    x = max(x, X);
  }
  for (int i = 0; i < m; i++)
  {
    int Y;
    cin >> Y;
    y = min(y, Y);
  }

  if (y <= x)
  {
    cout << "War" << endl;
  }
  else
  {
    cout << "No War" << endl;
  }
}
