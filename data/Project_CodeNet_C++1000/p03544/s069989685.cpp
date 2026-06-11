#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<ll> v(n + 1);

  v.at(0) = 2;
  v.at(1) = 1;
  for (int i = 2; i <= n; i++)
  {
    v.at(i) = v.at(i - 1) + v.at(i - 2);
  }
  cout << v.at(n) << endl;
}
