#include <iostream>
#include <string>
using namespace std;

int main() {
  string n;
  cin >> n;
  int cnt = 0;
  for (int i = 0; i < 4; ++i) if (n[i] == '2') ++cnt;
  cout << cnt << '\n';
  return 0;
}
