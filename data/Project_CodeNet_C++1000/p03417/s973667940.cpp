#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  ll h, w;
  cin >> h >> w;
  ll ans = 0;
  if (h==1 && w==1) {
    cout << "1" << endl;
    return 0;
  }
  if (min(h, w)==1) {
    ans = h*w-2;
    cout << ans << endl;
    return 0;
  }
  ans = (h-2)*(w-2);
  cout << ans << endl;
  return 0;
}