#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  string s;
  cin >> s;
  int n = s.length();
  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'x') {
      cnt++;
    }
  }
  if(cnt <= 7) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}