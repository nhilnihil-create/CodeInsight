#include <iostream>
#include <string>
using namespace std;

int main() {
  int a, b, k, max, cnt;
  cin >> a >> b >> k;
  cnt = 0;
  for (int i = min(a, b); i > 0; i--) {
    if (a % i == 0 && b % i == 0) {
      max = i;
      if (++cnt == k) break;
    }
  }
  cout << max << endl;
}