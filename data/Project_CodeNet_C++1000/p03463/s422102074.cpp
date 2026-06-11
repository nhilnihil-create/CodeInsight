#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, A, B;
  cin >> N >> A >> B;
  if ((B - A) % 2)
    cout << "Borys" << endl;
  else
    cout << "Alice" << endl;
  return 0;
}
