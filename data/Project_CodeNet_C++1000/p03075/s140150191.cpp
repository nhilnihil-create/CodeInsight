#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  vector<int> v(5);
  int k, a = 5, max = 0;

  for (int i = 0; i < a; ++i)
    cin >> v[i];

  cin >> k;

  for (int i = 0; i < a; ++i)
  {
    for (int j = i + 1; j < a; ++j)
    {
      if (v[j] - v[i] > max)
        max = v[j] - v[i];
    }
  }

  if (max > k)
    cout << ":(\n";
  else
    cout << "Yay!\n";

  return 0;
}