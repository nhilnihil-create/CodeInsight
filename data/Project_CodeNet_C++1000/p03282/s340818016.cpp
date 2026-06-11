#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  string s;
  ll k;
  cin >> s >> k;

  for (int i = 0; i < k; i++) {
    if (s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
  }

  cout << 1 << endl;
}