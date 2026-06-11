#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  vector<ll> la(n), sa(n+1);
  for (ll &a: la) cin >> a;
  for (ll i = 0; i < n; ++i) { 
    sa[i+1] = sa[i]+la[i];
  }
  int l, r;
  auto f1 = [&](int c, int k) { 
    return sa[k+1]-2*sa[c+1];
  };
  auto f2 = [&](int c, int k) { 
    return sa[n]+sa[k+1]-2*sa[c+1];
  };
  ll ans = sa[n];
  for (int i = 1; i < n-2; ++i) {
    l = 0, r = i;
    while (r-l>1) {
      int c = (l+r)/2;
      ll v = f1(c, i);
      if (v > 0) l = c; else r = c;
    }
    ll min1 = min(sa[l+1], sa[i+1]-sa[l+1]);
    ll max1 = max(sa[l+1], sa[i+1]-sa[l+1]);
    if (l > 0) {
      min1 = max(min1, min(sa[l], sa[i+1]-sa[l]));
      max1 = min(max1, max(sa[l], sa[i+1]-sa[l]));
    }
    if (l+1 < i) {
      min1 = max(min1, min(sa[l+2], sa[i+1]-sa[l+2]));
      max1 = min(max1, max(sa[l+2], sa[i+1]-sa[l+2]));
    }
    // cerr << i << " " << l << " " << min1 << " " << max1 << endl;

    l = i+1, r = n;
    while (r-l>1) {
      int c = (l+r)/2;
      ll v = f2(c, i);
      if (v > 0) l = c; else r = c;
    }
    ll min2 = min(sa[l+1]-sa[i+1], sa[n]-sa[l+1]);
    ll max2 = max(sa[l+1]-sa[i+1], sa[n]-sa[l+1]);
    if (l > i) {
      min2 = max(min2, min(sa[l]-sa[i+1], sa[n]-sa[l]));
      max2 = min(max2, max(sa[l]-sa[i+1], sa[n]-sa[l]));
    }
    if (l+1 < n) {
      min2 = max(min2, min(sa[l+2]-sa[i+1], sa[n]-sa[l+2]));
      max2 = min(max2, max(sa[l+2]-sa[i+1], sa[n]-sa[l+2]));
    }
    // if (i == 3) {
    //   cerr << "[!]" << sa[n]-sa[l+1] << " " << sa[l+1]-sa[i+1] << " " << sa[n]-2*sa[l+1]+sa[i+1] << endl;
    // }
    // cerr << i << " " << l << " " << min2 << " " << max2 << endl;
    ll ma = max(max1, max2);
    ll mi = min(min1, min2);
    ans = min(ans, ma-mi);
    // cerr << i << " " << ma-mi << endl;
  }
  cout << ans << endl;
}
