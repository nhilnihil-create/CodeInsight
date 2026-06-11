#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
  int64_t N;
  cin >> N;
  vector<int64_t> A(N, 0);
  vector<int64_t> csA(N+1, 0);
  {
    int64_t tmp;
    for (int i = 0; i < N; i++)
    {
      cin >> tmp;
      A[i] = tmp;
      csA[i+1] = tmp + csA[i];
    }
  }

  int64_t diff;
  diff = 9223372036854775807;

  int64_t p, q, r, s;
  int64_t mid0 = 0;
  int64_t mid2 = 2;

  for (int64_t mid1 = 0; mid1 < N - 2; mid1++)
  {
    int64_t diff0, diff2;
    diff0 = diff2 = 9223372036854775807;
    
    // mid0 search
    for (int64_t i = mid0; i < mid1; i++)
    {
      int64_t tmpp = csA[i+1] - csA[0];
      int64_t tmpq = csA[mid1+1] - csA[i+1];
      int64_t tmpdiff0 = abs(tmpp - tmpq);
      if (diff0 > tmpdiff0)
      {
        mid0 = i;
        diff0 = tmpdiff0;
        p = tmpp;
        q = tmpq;
      }
      else
      {
        break;
      }
    }

    // mid2 search
    int64_t start = (mid1 > mid2)? mid1 : mid2;
    for (int64_t i = start; i < N - 1; i++)
    {
      int64_t tmpr = csA[i+1] - csA[mid1+1];
      int64_t tmps = csA[N] - csA[i+1];
      int64_t tmpdiff2 = abs(tmpr - tmps);
      if (diff2 > tmpdiff2)
      {
        mid2 = i;
        diff2 = tmpdiff2;
        r = tmpr;
        s = tmps;
      }
      else
      {
        break;
      }
    }

    // check finaldiff
    int64_t tmpdiff = max({p, q, r, s}) - min({p, q, r, s});
    if (diff > tmpdiff)
      diff = tmpdiff;
  }

  cout << diff << endl;

  return 0;
}
  
