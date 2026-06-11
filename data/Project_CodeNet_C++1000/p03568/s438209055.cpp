#include <iostream>

using namespace std;

int main() {
  int N, A;
  cin >> N;
  int ans{1};
  int o{1};
  while (cin >> A) {
    ans *= 3;
    if (A%2==0) o *= 2;
  }
  cout << ans - o << endl;
  return 0;
}
