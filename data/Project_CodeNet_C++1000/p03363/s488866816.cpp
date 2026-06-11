#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  ll R[N+1];
  R[0] = 0;
  map<ll,ll> mp;
  mp[0]++;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    R[i+1] = R[i] + A[i];
    mp[R[i+1]]++;
  }
  ll ans = 0;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
     ll num = itr->second;
     ans += (num * (num - 1)) / 2;
  }
  cout << ans << endl;
  return 0;
}