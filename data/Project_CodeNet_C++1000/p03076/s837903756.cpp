#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  vector<int> a(5),b(5);
  rep(i,0,5) {cin >> a[i]; b[i] = i;}
  sort(a.begin(), a.end());
  int ans = 1000;
  do {
    int k = 0;
    rep(i,0,5) {
      k += a[b[i]];
      if (i < 4) {
        while(k % 10 != 0) k++;
      }
    }
    ans = min(ans,k);
  } while(next_permutation(b.begin(), b.end()));
  cout << ans << endl;
  return 0;
}
