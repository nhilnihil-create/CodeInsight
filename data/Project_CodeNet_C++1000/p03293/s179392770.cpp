#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S, T;
  cin >> S >> T;

  int N = S.size();
  rep(i, N) {
    string newS = S.back() + S.substr(0, N-1);
    if(newS == T) {
      cout << "Yes" << endl;
      return 0;
    }
    S = newS;
  }
  cout << "No" << endl;
  return 0;
}