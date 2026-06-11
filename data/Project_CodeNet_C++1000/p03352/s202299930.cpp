#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x;
  cin >> x;
  vector<bool> ok(x+1);
  ok[1] = true;
  for(int b = 2; b <= 32; b++) {
    int v = b*b;
    while(v <= x) {
      ok[v] = true;
      v *= b;
    }
  }
  for(int i = x; i >= 1; i--) {
    if(ok[i]) {
      cout << i << endl;
      return 0;
    }
  }
}