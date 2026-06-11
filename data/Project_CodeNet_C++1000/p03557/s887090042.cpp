#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

int main()	{
  int n;
  cin >> n;
  vector<long long int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  long long res = 0;
  for (int i = 0; i < n; i++)	{
    long long a_term = max(0ll, (long long)(lower_bound(a.begin(), a.end(), b[i]) - a.begin()));
    long long b_term = max(0ll, (long long)(n - (long long)(upper_bound(c.begin(), c.end(), b[i]) - c.begin()))); 
    res += max(0ll, a_term * b_term);
  }
  cout << res << endl;
  return 0;
}