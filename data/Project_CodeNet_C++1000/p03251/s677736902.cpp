#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, x, y, mx, my;
  cin >> n >> m >> mx >> my;
  for (int i = 0; i < n; i++)
  {
    cin >> x;
    mx = max(mx, x);
  }
  for (int i = 0; i < m; i++)
  {
    cin >> y;
    my = min(my, y);
  }
  cout << (mx < my ? "No War" : "War") << endl;
}