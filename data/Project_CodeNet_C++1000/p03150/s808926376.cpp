#include <iostream>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  string K = "keyence";
  if (S == K) {
    cout << "YES" << endl;
    return 0;
  }

  int sn = S.size();
  for (int i = 0; i < sn; ++i) {
    for (int j = i; j < sn; ++j) {
      // delete i~j
      string check = S.substr(0, i) + S.substr(j + 1, sn - (j + 1));
      if (check == K) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
