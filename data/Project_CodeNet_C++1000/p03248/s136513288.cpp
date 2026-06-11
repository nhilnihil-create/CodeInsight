// g++ A.cpp -Wall -Wextra -Woverflow -Wshadow -O2
#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <cstring>
#include <climits>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>
#include <bitset>
 
using namespace std;
 
typedef long long LL;
typedef pair<int, int> pii;

string s;
int main() {
  ios::sync_with_stdio(false); 
  cin >> s;
  int n = s.size();
  s = '?' + s;
  if (s[n] == '1' || s[1] == '0') {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> pos;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[n - i]) {
      cout << -1 << '\n';
      return 0;
    }
    if (s[i] == '1') {
      pos.push_back(i);
    }
  }
  pos.push_back(n);
  for (int i = 1, j = 0; i < n && j < pos.size(); i++) {
    if (i == pos[j]) j++;
    cout << i << ' ' << pos[j] << '\n';
  }
}