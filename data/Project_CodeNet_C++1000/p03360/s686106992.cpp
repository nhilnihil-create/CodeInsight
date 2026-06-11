#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
  int a[3];
  int k;
  int sum = 0;

  for ( int i = 0; i < 3; ++i ) cin >> a[i];
  sort(a,a+3);
  cin >> k;

  for ( int i = 0; i < k; ++i ) a[2] *= 2;
  for ( int i = 0; i < 3; ++i ) sum += a[i];

  cout << sum << "\n";
}
