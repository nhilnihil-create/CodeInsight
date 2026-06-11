#include <iostream>
#include <map>

using namespace std;

const int N = 2e6 + 10;

int a[N];
map<int, int> s;
int n;

int main() {

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int found = 0;
  for (int i = 0; i+1 < n; ++i) {
    if (a[i] >= a[i+1]) {
      found = true;
    }
  }

  if (!found) {
    cout << 1 << endl;
    return 0;
  }

  int lo = 2, hi = n;

  while (lo < hi) {
    const int x = (lo + hi) / 2;

    int valid = 1;
    s.clear();
    for (int i = 1; i < n; ++i) {
      while (!s.empty() && prev(s.end())->first >= a[i]) {
        s.erase(prev(s.end()));
      }

      if (a[i-1] >= a[i]) {
        int l = a[i] - 1;
        while (l >= 0 && s[l] == x-1) {
          s[l--] = 0;
        }
        if (l < 0) {
          valid = 0;
          break;
        }
        s[l]++;
      }
    }

    if (valid) {
      hi = x;
    } else {
      lo = x + 1;
    }
  }

  cout << lo << endl;

  return 0;
}
