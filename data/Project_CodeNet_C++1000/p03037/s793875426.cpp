#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  int maxL = 0, minR = n;
  for(int i = 0; i < m; ++i)
  {
    int l, r;
    cin >> l >> r;
    if(maxL < l) maxL = l;
    if(minR > r) minR = r;
  }
  
  int ans = max(minR - maxL + 1, 0);
  cout << ans << endl;
}