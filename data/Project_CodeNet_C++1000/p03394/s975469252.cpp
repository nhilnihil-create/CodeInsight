#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
  cin >> n;

  int ds[] = {2,3,4,6};
  unordered_set<int> result;
  if (n == 3) {
    result.insert({2, 5, 63});
  } else if (n == 4) {
    result.insert({2, 5, 20, 63});
  } else if (n == 5) {
    result.insert({2, 5, 20, 30, 63});
  } else {
    int s = 0;
    int last = 0;
    for (int k = 0; result.size() < n; k++) {
      for (int d = 0; d < 4 && result.size() < n; d++) {
        last = 6*k+ds[d];
        result.insert(last);
        s += last;
      }
    }

    if (s % 6 == 2) {
      result.erase(8);
      result.insert((last / 6 + 1) * 6);
    } else if (s % 6 == 3) {
      result.erase(9);
      result.insert((last / 6 + 1) * 6);
    } else if (s % 6 == 5) {
      result.erase(9);
      result.insert(last / 6 * 6 + 4);
    }
  }

  for (int v : result)
    cout << v << " ";
  cout << endl;

  return 0;
}
