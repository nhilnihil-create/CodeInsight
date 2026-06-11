#include <iostream>
#include <string>
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define SIZE(x) ll(x.size())

typedef long long ll;

using namespace std;
int main() {
  string S, T;
  cin >> S >> T;
  int num = SIZE(S);
  REP(i, num) {
    if (S == T) {
      cout << "Yes";
      return 0;

    } else {
      T = T[num - 1] + T.substr(0, num - 1);
    }
  }
  cout << "No";
  return 0;
}