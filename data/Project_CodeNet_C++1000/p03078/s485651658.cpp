#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(x, y) x = max(x, y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int x, y, z, k; cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z), d, ans;
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());

  rep(i, x){
    rep(j, y){
      d.push_back(a[i] + b[j]);
    }
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  rep(i, min(k, (int)d.size())){
    rep(j, z){
      ans.push_back(d[i] + c[j]);
    }
  }

  sort(ans.begin(), ans.end());
  reverse(ans.begin(), ans.end());
  rep(i, k){
    cout << ans[i] << endl;
  }
  return 0;
}
