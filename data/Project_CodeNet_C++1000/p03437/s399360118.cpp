#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t X, Y;
  cin >> X >> Y;
  if (X % Y == 0)
    cout << -1 << endl;
  else
    cout << X * (Y - 1) << endl;
}