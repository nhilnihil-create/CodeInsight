#include <iostream>
#include <string>
using namespace std;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s == "Y") {
      cout << "Four" << endl;
      return 0;
    }
  }
  cout << "Three" << endl;
}