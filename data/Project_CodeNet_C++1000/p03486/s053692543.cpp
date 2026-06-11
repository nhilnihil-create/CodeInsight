#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

#define ALL(x) begin(x), end(x)

int main() {
  string s,t;
  cin >> s >> t;
  sort(ALL(s));
  sort(ALL(t),greater<>());
  cout << (s < t ? "Yes" : "No") << endl;
  return 0;
}
