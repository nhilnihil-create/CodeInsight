#include <iostream>
#include <string>
using namespace std;
int main()
{
  string S, T;
  cin >> S >> T;
  int len = S.length();
  bool ans = false;
  for (int i = 0; i < len; i++) {
    int p;
    for (p = 0; p < len; p++) {
      if (S[p] != T[(p+i)%len]) break;
    }
    if (p == len) ans = true;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
