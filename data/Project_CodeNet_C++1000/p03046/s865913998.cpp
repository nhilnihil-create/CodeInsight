#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
#define revrep(i,n,g) for (int i = n; i >= g; i--)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int m,k;
  cin >> m >> k;
  if (m <= 1) {
    if (m == 0 && k == 0) {
      cout << "0 0" << endl;
    } else if (m == 1 && k == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
  } else {
    if ((1<<m) <= k) cout << -1 << endl;
    else {
      rep(i,0,1<<m) {
        if (i == k) continue;
        cout << i << " ";
      }
      cout << k << " ";
      revrep(i,(1<<m)-1,0) {
        if (i == k) continue;
        cout << i << " ";
      }
      cout << k << endl;
    }
  }
  return 0;
}