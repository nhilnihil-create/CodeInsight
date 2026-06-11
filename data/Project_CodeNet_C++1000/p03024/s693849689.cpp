#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, v = 0;
  string s;
  cin >> s;
  n = s.size();
  rep(i, n) if(s[i] == 'o') ++v;
  if(v-n+8 > 0) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}