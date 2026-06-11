#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long LL;

int main() {
  string S; cin >> S;
  map<char, int> m;
  for (char c : S) m[c]++;

  if (m['a'] == 1 && m['b'] == 1 && m['c'] == 1) cout << "Yes" << endl;
  else                                           cout << "No" << endl;
}
