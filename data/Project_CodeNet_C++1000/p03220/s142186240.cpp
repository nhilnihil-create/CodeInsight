#include<iostream>
#include<cmath>
#define rep(i, n) for (int i = 0; i < (n); i ++)

#define MILL 1000
#define DIFF 6
using namespace std;

int main()
{
  int n;
  cin >> n;
  
  int t, a;
  cin >> t >> a;
  t *= MILL;
  a *= MILL;
  
  int min_index = -1;
  int min_diff = 1000000001;
  int h;
  rep(i, n)
  {
    cin >> h;
    int diff = abs(a - (t - h * DIFF));
    if (diff < min_diff)
    {
      min_diff = diff;
      min_index = i;
    }
  }

  cout << min_index + 1;
  return 0;
}
