#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int a[200010], b[200010];
int na[200010], nb[200010];

ll cnt(int k) {
  int T = 1 << k;
  for (int i = 0; i < N; i++) {
    na[i] = a[i] % (T << 1);
    nb[i] = b[i] % (T << 1);
  }
  vector<int> v;
  for (int i = 0; i < N; i++) {
    v.emplace_back(nb[i]);
  }
  sort(v.begin(), v.end());
  ll res = 0;
  for (int i = 0; i < N; i++) {
    res += lower_bound(v.begin(), v.end(), 2*T - na[i]) - lower_bound(v.begin(), v.end(), T - na[i]);
    res += lower_bound(v.begin(), v.end(), 4*T - na[i]) - lower_bound(v.begin(),
    v.end(), 3*T - na[i]);
  }
  return res;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  ll ans = 0;
  for (int i = 0; i <= 28; i++) {
    ans += (cnt(i) & 1 ? (1 << i) : 0);
  }
  cout << ans << endl;

  return 0;
}