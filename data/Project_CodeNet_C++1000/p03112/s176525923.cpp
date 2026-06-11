#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

const ll MAX = 1000000000000001;

int main(){
  int a, b, q; cin >> a >> b >> q;
  vector<ll> s(a), t(b), u(q), ans(q);
  rep(i, a) cin >> s[i];
  rep(i, b) cin >> t[i];
  rep(i, q) cin >> u[i];
  rep(i, q){
    ll x = u[i], sl, sr, tl, tr;
    int sid = lower_bound(s.begin(), s.end(), x) - s.begin();
    int tid = lower_bound(t.begin(), t.end(), x) - t.begin();
    if(sid == 0){
      sl = -MAX;
    }
    else{
      sl = s[sid - 1];
    }
    if(sid == s.size()){
      sr = MAX;
    }
    else{
      sr = s[sid];
    }
    if(tid == 0){
      tl = -MAX;
    }
    else{
      tl = t[tid - 1];
    }
    if(tid == t.size()){
      tr = MAX;
    }
    else{
      tr = t[tid];
    }
    //cout << sl << " " << sr << " " << tl << " " << tr << endl;

    ans[i] = max(sr, tr) - x;
    ans[i] = min(ans[i], x - min(sl, tl));
    ans[i] = min(ans[i], (sr - x) + sr - tl);
    ans[i] = min(ans[i], tr - x + tr - sl);
    ans[i] = min(ans[i], x - sl + tr - sl);
    ans[i] = min(ans[i], x - tl + sr - tl);

  }

  rep(i, q) cout << ans[i] << endl;
  return 0;
}
