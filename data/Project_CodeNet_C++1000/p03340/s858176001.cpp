#include <iostream>

using namespace std;

int main()
{
  int n; cin >> n;
  int a[200000]; for (int i = 0; i < n; ++i) cin >> a[i];
  
  int l = 0, r = 0, sum = 0;
  long long ans = 0;
  while (r < n)
    if (sum + a[r] == (sum ^ a[r]))
      sum += a[r++];
    else {
      ans += r-l;
      sum -= a[l++];
    }
  ans += (long long)(r-l)*(r-l+1)/2;
  
  cout << ans << endl;
  return 0;
}