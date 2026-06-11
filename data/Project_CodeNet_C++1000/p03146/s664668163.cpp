#include <bits/stdc++.h>
using namespace std;
int main()
  {int s; cin >> s;
  map<int, int> m;
  for (int i{1}; ; ++i)
    {if (m[s]) cout << i, exit(0);
    ++m[s]; s = s % 2 ? 3 * s + 1 : s / 2;}}