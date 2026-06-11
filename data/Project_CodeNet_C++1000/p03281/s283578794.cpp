#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int cnt = 0;
    if (i % 2 == 0) continue;
    for (int j = 1; j <= i; j++) {
      if (i % j == 0) cnt++;
    }
    if (cnt == 8) ans++;
  }
  cout << ans << endl;
}