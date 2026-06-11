#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  string s, t = "";
  int w, tmp = 0;
  cin >> s >> w;
  while(tmp < s.size()){
    t += s[tmp];
    tmp += w;
  }
  cout << t << endl;
  return 0;
}