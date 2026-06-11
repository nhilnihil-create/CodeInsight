#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
  int max,min;
  int n;

  cin >> n;
  scanf("%d", &max);
  min = max;
  --n;
  while(n--) {
    int tmp;
    scanf("%d", &tmp);
    if ( tmp < min ) min = tmp;
    if ( tmp > max ) max = tmp;
  }

  cout << abs(min-max) << endl;
}
