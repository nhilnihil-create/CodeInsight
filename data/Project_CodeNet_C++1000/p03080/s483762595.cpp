#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, r = 0, b = 0;
  string s;
  cin >> n >> s;
  rep(i, n){
    if(s[i] == 'R') ++r;
    else if(s[i] == 'B') ++b;
  }
  if(r > b) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}