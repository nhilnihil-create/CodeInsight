#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <cassert>
#include <cstring>
#include <chrono>

using namespace std;

typedef long long ll;

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];

  int result = 0;
  for (int a = 0; a < n; ++a) {
    vector<string> ss(n);
    for (int i = 0; i < n; ++i) {
      ss[(i + a) % n] = s[i];
    }
    bool ok = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (ss[i][j] != ss[j][i]) {
          ok = false;
          break;
        }
      }
    }
    if (ok) result += n;
  }
  cout << result << endl;
  return 0;
}
