#include <cmath>
#include <iostream>
#include <vector>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int div_count(int n) {
  vector<int> v;
  for (int i = 1; i <= sqrt(n); ++i) {
    if (n % i == 0) {
      int d = n / i;
      v.push_back(i);
      if (i != d) {
        v.push_back(d);
      }
    }
  }
  return v.size();
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i += 2) {
    int divs = div_count(i);
    if (divs == 8) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
