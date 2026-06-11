#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define FOR(i, a, b) for (int i=(a); i<(b); i++)
using Graph = vector<vector<int>>;

int main() {
  long long X,Y;
  cin >> X >> Y;
  int ans = 1;
  while(X*2 <= Y) {
    ans++;
    X *= 2;
  }
  cout << ans << endl;
  
  return 0;
}