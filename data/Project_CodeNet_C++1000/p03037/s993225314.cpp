#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n,m;
  cin >> n >> m;
  int l,r;
  int ansl = 1;
  int ansr = n;
  rep(i,m) {
    cin >> l >> r;
    if (ansl < l) ansl = l;
    if (ansr > r) ansr = r;
  }
  if (ansr-ansl+1>0) cout << ansr-ansl+1 << endl;
  else cout << 0 << endl;
  return 0;
}
