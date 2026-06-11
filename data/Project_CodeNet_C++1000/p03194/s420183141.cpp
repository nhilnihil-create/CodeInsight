#include <iostream>
#include <math.h>
#include <map>
using namespace std;
int main()
{
  long N, P;
  cin >> N >> P;
  map<long, long> mp;
  for (long i = 2; i * i <= P; i++)
  {
    while (P % i == 0)
    {
      if (mp.find(i) == mp.end())
        mp[i] = 1;
      else
        mp[i] = mp[i] + 1;
      P /= i;
    }
  }
  if (P != 1)
  {
    if (mp.find(P) == mp.end())
      mp[P] = 1;
    else
      mp[P] = mp[P] + 1;
  }
  long ans = 1;
  for (auto m : mp)
  {
    ans *= pow(m.first, m.second / N);
  }
  cout << ans << endl;
  return 0;
}