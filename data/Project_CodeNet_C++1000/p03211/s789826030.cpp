#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string s;
  cin >> s;
  int minm = 1e8;
  for(int i = 2; i < (int)s.size(); i++) {
    int ans = (s[i-2] - '0')*100 + (s[i-1] - '0')*10 + (s[i] - '0');
    minm = min(minm, abs(753-ans));
  }
  cout << minm << endl;
  return 0;
}
    