#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;

  cin >> n;

  vector<int> v(n);
  vector<int> c(n);
  vector<int> sa(n);

  int total = 0;

  rep(i, n)
  {
    cin >> v.at(i);
  }

  rep(i, n)
  {
    cin >> c.at(i);
  }

  rep(i, n)
  {
    sa.at(i) = v.at(i) - c.at(i);
    if(sa.at(i)  >0)
      total += sa.at(i);
  }

  cout << total;
}
