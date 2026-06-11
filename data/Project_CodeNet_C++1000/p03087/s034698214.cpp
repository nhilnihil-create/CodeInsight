#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> rui(n);
    rui[0] = 0;
    for (int i = 1; i < n; i++) {
      if (s[i-1] == 'A' && s[i] == 'C') rui[i] = rui[i-1] + 1;
      else rui[i] = rui[i-1];
    }
    rep(i,q) {
      int l, r;
      cin >> l >> r;
      l--; r--;
      int ans = rui[r]-rui[l];
      cout << ans << endl;
    }
    return 0;
}