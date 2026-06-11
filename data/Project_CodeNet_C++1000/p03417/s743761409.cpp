#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;

int main ()
{
  ll min,max;
  ll sum = 0;

  cin >> min >> max;

  if ( min > max ) swap(min,max);

  if ( min == 1 ) {
    if ( max == 1 ) sum += 1;
    else sum += (max-2);
  } else if ( min == 2 ) {
    sum = 0;
  } else {
    sum += (min-2)*(max-2);
  }

  cout << sum << "\n";
}
