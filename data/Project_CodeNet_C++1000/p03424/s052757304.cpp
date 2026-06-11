#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  bool four = false;
  rep(i, N) {
    string S;
    cin >> S;
    if (S == "Y") four = true;
  }
  if (four)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
  return 0;
}
