#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  vector<int> a(3);

  rep(i, 3) cin >> a[i];

  sort(a.begin(), a.end());

  cout << abs(a.at(2) - a.at(1)) + abs(a.at(1) - a.at(0));
}
