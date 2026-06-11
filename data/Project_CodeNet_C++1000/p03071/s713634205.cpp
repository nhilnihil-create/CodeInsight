#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int a, b;
  cin >> a >> b;

  int mx = max(a, b);
  //int mn = min(a, b);
  if (a == b) cout << a + b << endl;
  else cout << 2 * mx - 1 << endl;
}
