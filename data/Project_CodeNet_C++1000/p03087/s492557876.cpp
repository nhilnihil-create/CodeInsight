#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
int cnt[100010];
int main() {
  int n,q;
  string s;
  cin >> n >> q >> s;
  int ac = 0;
  rep(i,n-1) {
    if (s[i] == 'A' && s[i+1] == 'C') {
      cnt[i+1] = cnt[i] + 1;
    } 
    else cnt[i+1] = cnt[i];
  }
  rep(i,q) {
    int l,r; cin >> l >> r;
    l--; r--;
   if (l == 0) cout << cnt[r] << endl;
   else cout << cnt[r] -  cnt[l] << endl;
  } 
  return 0;
}