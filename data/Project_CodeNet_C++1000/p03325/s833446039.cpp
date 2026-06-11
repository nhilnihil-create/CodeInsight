#include <iostream>

using namespace std;

int main() {
  int N, a, ans{};
  cin >> N;
  while(cin >> a) {
    while (a%2==0) {
      a >>= 1;
      ++ans;
    }
  }
  cout << ans << endl;
}
