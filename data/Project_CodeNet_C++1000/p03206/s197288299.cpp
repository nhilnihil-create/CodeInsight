#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  int d;
  cin >> d;
  cout << "Christmas";
  for (int i = 0; i < 25 - d; ++i) {
    cout << " Eve";
  }
  cout << endl;
  return 0;
}
