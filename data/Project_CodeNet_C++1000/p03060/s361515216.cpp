#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<int> c(n);
  for (auto &a : v)
    cin >> a;
  for (auto &a : c)
    cin >> a;
  int ans = 0;
  for (int i = 0; i < n; ++i)
    if (0 < v[i] - c[i])
      ans += v[i] - c[i];
  cout << ans << endl;
}