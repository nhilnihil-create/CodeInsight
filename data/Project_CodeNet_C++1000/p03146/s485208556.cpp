#include <bits/stdc++.h>
#include <functional>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

int f(int n) {
  if (n % 2 == 0) {
    return n / 2;
  }
  return 3 * n + 1;
}

int main() {
  int s;
  std::cin >> s;
  std::vector<int> a;

  a.push_back(s);
  int i = 1;
  bool ok = false;
  while (!ok) {
    int current = f(a[i - 1]);
    a.push_back(current);
    for (int j = 0; j < i; j++) {
      if (a[j] == current) {
        ok = true;
      }
    }
    i++;
  }
  std::cout << i << std::endl;
  return 0;
}
