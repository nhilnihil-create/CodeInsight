#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main()
{
  int n, m;
  cin >> n;
  m = n;
  int tmp = 0;
  for (int i = 0; i <= 8; i++)
  {
    tmp += n % 10;
    n /= 10;
    if (n == 0)
      break;
  }
  if (m % tmp == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
