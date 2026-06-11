#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n; cin >> n;
    vector<ll> h(n); for (int i=0; i<n; ++i) cin >> h[i];
    vector<ll> a(n); for (int i=0; i<n; ++i) cin >> a[i];
    ll res=0;
    set<pair<ll, ll>> st;
    st.insert({0ll, 0ll});
    for (int i=0; i<n; ++i) {
      auto it=prev(st.lower_bound({h[i], 0}));
      ll cost=a[i]+(*it).second;
      it++;
      while (it!=st.end()) {
        auto nxt=next(it);
        if ((*it).second<=cost) {
          st.erase(it);
        } else {
          break;
        }
        it=nxt;
      }
      st.insert({h[i], cost});
      res=max(res, cost);
    }

    cout << res << endl;
    return 0;
}