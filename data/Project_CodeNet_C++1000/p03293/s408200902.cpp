#include <iostream>
#define rep(S, L) for (int i = S; i < L; ++i)
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int l = s.size();
  int ok = false;
  for (int i = l - 1; i >= 0; --i) {
    string u = s.substr(i) + s.substr(0, i);
    if (t == u) {
      ok = true;
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
