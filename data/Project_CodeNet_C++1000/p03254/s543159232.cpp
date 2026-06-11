# include <iostream>
# include <algorithm>
using namespace std;

int main() {
  long long n, x; cin >> n >> x;
  long long a[n];
  long long a_sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a_sum += a[i];
  }
  
  if (x > a_sum) cout << n - 1 << endl;
  else if (x == a_sum) cout << n << endl;
  else {
    int ans = 0;
    sort(a, a + n);
    for (int a_i = 0; a_i < n; ++a_i) {
      x = x - a[a_i];
      if (x >= 0) ++ans;
    }
    cout << ans << endl;
  }
  
  return 0;
}