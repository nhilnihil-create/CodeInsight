#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;

int main() {
  string s;
  cin >> s;
  int prev = 0;
  s += '#';
  bool ok = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] != s[prev]) {
      if (i - prev >= 3) ok = true;
      prev = i;
    }
  }

  cout << (ok ? "Yes" : "No") << endl;
  return 0;
} 