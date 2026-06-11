#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, m, x;
  cin >> n >> m >> x;
  int a[n];
  for(int i = 0; i < m; ++i) cin >> a[i];
  
  int pos = m;
  for(int i = 0; i < m; ++i)
  {
    if(x <= a[i])
    {
      pos = i;
      break;
    }
  }
  
  int ans = min(pos, m - pos);
  cout << ans << endl;
}