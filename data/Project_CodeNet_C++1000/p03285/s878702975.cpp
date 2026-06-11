#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  
  bool ans = false;
  for (int i = 0; i <= n / 4; i++) {
    if ((n - i * 4) % 7 == 0) {
      ans = true;
      break;
    }
  }
  
  if (ans) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
