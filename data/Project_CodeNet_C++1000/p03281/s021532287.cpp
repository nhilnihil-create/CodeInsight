#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> vec(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    for (int j = i; j <= n; j += i)
      if (j % 2 == 1)
        ++vec[j];
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i)
    ans += vec[i] == 8;

  cout << ans << endl;
}
