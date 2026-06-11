#include <iostream>

using namespace std;

bool hoge(int n) {
  if (n == 0)
    return true;
  else if(n < 0)
    return false;
  else {
    return hoge(n - 4) || hoge(n - 7);
  }
}

int main() {
  int n;
  cin >> n;
  cout << (hoge(n) ? "Yes" : "No") << endl;
}
