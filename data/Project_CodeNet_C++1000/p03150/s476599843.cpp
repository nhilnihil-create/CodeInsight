#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  string s;
  cin >> s;
  string pt = "keyence";
  if (s == pt) {
    cout << "YES" << endl;
    return 0;
  }
  int n = s.size();
  for (int i = 0; i < n; ++i) {
    string s1 = s.substr(0, i);
    for (int j = i; j < n; ++j) {
      string s2 = s.substr(j, n);
      if (s1 + s2 == pt) {
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}