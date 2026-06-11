#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> N(3);
  for (int i = 0; i < 3; i++)
  {
    cin >> N[i];
  }
  sort(N.begin(), N.end());
  int r = 2 * N[2] - (N[1] + N[0]);
  if (r % 2 == 0)
  {
    cout << r / 2 << endl;
  }
  else
  {
    cout << (r + 3) / 2 << endl;
  }
}
