#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int n, a;
  int mina = 1000000000;
  int maxa = 0;
  cin >> n;
  rep(0, n) {
    cin >> a;
    mina = min(mina, a);
    maxa = max(maxa, a);
  }
  cout << maxa - mina << endl;
  return 0;
}
