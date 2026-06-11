#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  long long m = 1;
  for (int i = 0; i < n; i++) m *= a[i];
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    ans += a[i] - 1;
  }
  cout << ans << endl;
}