#include <bits/stdc++.h>
using namespace std;
int C[1000001], s, i;
int main()
  {cin >> s; while (++i, !C[s]++) s = s % 2 ? 3 * s + 1 : s / 2;
  cout << i;}