#include <bits/stdc++.h>
using namespace std;

int main()
{
  string n; cin >> n;
  int sum = 0;
  for(char c: n)
  {
    int a = c - '0';
    sum += a;
  }
  if (sum == 1)
  {
    cout << 10 << endl;
  }
  else
  {
    cout << sum << endl;
  }
  return 0;
}