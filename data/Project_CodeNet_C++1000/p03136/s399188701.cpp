#include <iostream>
#include <vector>
#include <algorithm>
#define int64 long long
using namespace std;

int main()
{
  int64 nn, tmp, sum = 0;
  cin >> nn;
  vector<int64> ll(nn);
  for(int64 ii = 0;ii < nn;ii++)
  {
    cin >> tmp;
    ll[ii] = tmp;
    sum += tmp;
  }
  sort(ll.begin(), ll.end());
  sum -= ll[nn - 1];
  if(sum > ll[nn - 1])
  {
    puts("Yes");
  }
  else
  {
    puts("No");
  }
  return 0;
}