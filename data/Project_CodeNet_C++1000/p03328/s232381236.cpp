#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int a, b, s, sum = 0;
  cin >> a >> b;
  s = b - a;
  for (int i = s; i >= 1; i--)
  {
    sum += i;
  }
  cout << sum - b << endl;
}
