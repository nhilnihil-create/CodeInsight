#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main() {
  int A,P;
  cin >> A >> P;
  
  int ans = (A*3 + P) / 2;

  cout << ans << endl;
  return 0;
}
