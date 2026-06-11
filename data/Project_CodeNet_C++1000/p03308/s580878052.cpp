#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  valarray<int> a(n);
  for (auto&& e : a) cin >> e;
  cout << a.max() - a.min() << endl;
}
