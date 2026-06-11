#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  vector<int> v(4, 0);
  rep(i, 6){
    int a;
    cin >> a;
    ++v[a-1];
  }
  int m = 0;
  rep(i, 4) m = max(m, v[i]);
  if(m < 3) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}