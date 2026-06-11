#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int A, B, Q;
  cin >> A >> B >> Q;
  vector<ll> alist(A);
  for (int i = 0; i < A; i++) {
    cin >> alist[i];
  }
  vector<ll> blist(B);
  for (int i = 0; i < B; i++) {
    cin >> blist[i];
  }

  while(Q--) {
    ll ans = LLONG_MAX;
    ll p;
    cin >> p;
    int ai = lower_bound(alist.begin(), alist.end(), p) - alist.begin();
    for (int i = max(0, ai - 1); i < min(A, ai + 1); i++) {
      ll tmp = abs(alist[i] - p);
      int bi = lower_bound(blist.begin(), blist.end(), alist[i]) - blist.begin();
      for (int j = max(0, bi - 1); j < min(B, bi + 1); j++) {        
        ans = min(ans, tmp + abs(blist[j] - alist[i]));
      }
    }

    int bi = lower_bound(blist.begin(), blist.end(), p) - blist.begin();
    for (int i = max(0, bi - 1); i < min(B, bi + 1); i++) {
      ll tmp = abs(blist[i] - p);
      int ai = lower_bound(alist.begin(), alist.end(), blist[i]) - alist.begin();
      for (int j = max(0, ai - 1); j < min(A, ai + 1); j++) {        
        ans = min(ans, tmp + abs(alist[j] - blist[i]));
      }
    }
    cout << ans << endl;
  }
  return 0;
}