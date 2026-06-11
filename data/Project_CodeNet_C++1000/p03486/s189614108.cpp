#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
  vector <char> s, t;
  string S, T;
  cin >> S >> T;
  for (unsigned int i = 0; i < S.length(); i++) {
    char c = S[i];
    s.push_back(c);
  }
  for (unsigned int i = 0; i < T.length(); i++) {
    char c = T[i];
    t.push_back(c);
  }
  sort(s.begin(), s.end());
  sort(t.begin(), t.end(), [](const int& x, const int& y) {return x > y;});
  bool ans = false;
  for (int i = 0; i < t.size(); i++) {
    if (i >= s.size()) {
      ans = true;
      break;
    }
    if (s[i] < t[i]) {
      ans = true;
      break;
    }
    if (s[i] > t[i]) {
      ans = false;
      break;
    }
  }
  if (ans) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
