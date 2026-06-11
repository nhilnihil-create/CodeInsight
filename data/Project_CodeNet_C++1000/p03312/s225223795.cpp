#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N; cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<ll> pref(N+1);
  for (int i = 0; i < N; i++) pref[i+1] = pref[i] + A[i];
  ll ans = pref[N];
  auto getHalf = [&](const multiset<ll>& ms, ll v) {
    auto it = ms.lower_bound((v+1)/2);
    ll res = 0;
    if (it != ms.end()) res = max(res, v - *it);
    if (it != ms.begin()) res = max(res, *(--it));
    return res;
  };
  multiset<ll> prefs;
  multiset<ll> suffs;
  prefs.insert(pref[1]);
  for (int i = 2; i <= N-1; i++) suffs.insert(pref[N]-pref[i]);
  for (int i = 2; i <= N-2; i++) {
    suffs.erase(suffs.find(pref[N]-pref[i]));
    ll p = pref[i];
    ll s = pref[N]-pref[i];
    ll ph = getHalf(prefs, p);
    ll sh = getHalf(suffs, s);
    ans = min(ans, max(s-sh,p-ph) - min(ph, sh));
    prefs.insert(pref[i]);
  }
  cout << ans << '\n';
}