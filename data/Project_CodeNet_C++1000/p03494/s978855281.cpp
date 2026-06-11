#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, sum = 0;
  bool flag = true;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++)
  {
    cin >> A.at(i);
  }

  while (flag)
  {
    for (int i = 0; i < n; i++)
    {
      if (A.at(i) % 2 == 1)
      {
        flag = false;
        break;
      }
      A.at(i) /= 2;
    }
    if (flag)
      sum++;
  }
  cout << sum << endl;
}
