#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int main() {
  int n;
  string s;
  std::cin >> n >> s;

  int maxv = 0;
  for (int i = n - 1; i >= 0; --i) {
    int num = 0;
    // increment num if both include the same alphabet
    rep(j, 27) {
      rep(k, i) {
        if ('a' + j == s[k]) {
          for (int l = i; l < n; ++l) {
            {
              if ('a' + j == s[l]) {
                num++;
                break;
              }
            }
          }
          break;
        }
      }
    }
    maxv = max(maxv, num);
  }

  std::cout << maxv << std::endl;
  return 0;
}
