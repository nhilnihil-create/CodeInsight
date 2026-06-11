#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, a;cin >>n>>a;
  while (n >= 500) {
    n -= 500;
  }
  // int amari = n / 500;
  if (n <= a) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}