#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll N, M; cin >> N >> M;
  ll a[N];
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll sum[N+1];
  sum[0] = 0;
  for (ll i = 1; i < N+1; i++) {
    sum[i] = sum[i-1]+a[i-1];
  }
  map<ll,ll> count;
  set<ll> mod;
  for (ll i = 0; i < N+1; i++) {
    count[sum[i]%M]++;
    mod.insert(sum[i]%M);
  }
  ll res = 0;
  for (auto it = mod.begin(); it != mod.end(); it++) {
    if (count[*it] > 0) res+=count[*it]*(count[*it]-1)/2;
  }
  cout << res << endl;
}