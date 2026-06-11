#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<int> rt[11];

int main() {
    int n, m;
    cin >> n >> m;
    rep(i,m) {
      int k;
      cin >> k;
      rep(j,k) {
        int s;
        cin >> s;
        rt[i].push_back(s);
      }
    }
    vector<int> t(m);
    rep(i,m) cin >> t[i];
    int ans = 0;
    rep(is, 1<<n) {
      bool flag = true;
      rep(i,m) {
        int l = 0;
        for (int x : rt[i]) {
          x--;
          l ^= is>>x&1;
        }
        if (l != t[i]) flag = false;
      }
      if (flag) ans++;
    }
    cout << ans << endl;
    return 0;
}