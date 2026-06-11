#include <algorithm>
#include <iomanip>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  sort(s.begin(), s.end());
  sort(t.rbegin(), t.rend());
  if (s < t)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
