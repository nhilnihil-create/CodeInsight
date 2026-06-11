#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) (v).begin(), (v).end()

using namespace std;
using ll = long long;

int main()
{
  vector<int> n(4); REP(i, 4) cin >> n[i];
  sort(ALL(n));
  if (n == vector<int>{1, 4, 7, 9}) cout << "YES" << endl;
  else cout << "NO" << endl;
}