#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  int a, b, k;
  cin >> a >> b >> k;
  int n = min(a, b);
  vector<int> v;
  for (int i = 1; i <= n; i++)
  {
    if (a % i == 0 && b % i == 0)
      v.push_back(i);
  }
  cout << v[v.size() - k] << endl;
  return 0;
}