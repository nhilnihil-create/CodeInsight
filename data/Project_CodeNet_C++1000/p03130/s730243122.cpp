#include <iostream>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int d[4] = {0};
  int a, b;
  for (int i = 0; i < 3; i++) {
    cin >> a >> b;
    d[a - 1]++;
    d[b - 1]++;
  }
  int c = 0;
  for (auto e : d) {
    if (e % 2 == 1) c++;
  }
  if (c == 2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
