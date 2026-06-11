#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vll v(n);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  vll sum(n + 1);
  for (int i = 0; i < n; i++)
    sum[i + 1] = sum[i] + v[i];
  ll ans = 1000000000000000LL;
  int l = 1, r = 3;
  for (int i = 2; i <= n - 2; i++) {
    while (l < i - 1 && abs((sum[i] - sum[l]) - (sum[l])) >=
                            abs((sum[i] - sum[l + 1]) - (sum[l + 1]))) {
      l++;
    }
    r = max(r, i + 1);
    while (r < n - 1 &&
           abs((sum[n] - sum[r]) - (sum[r] - sum[i])) >=
               abs((sum[n] - sum[r + 1]) - (sum[r + 1] - sum[i]))) {
      r++;
    }
    ll w[4];
    w[0] = sum[l];
    w[1] = sum[i] - sum[l];
    w[2] = sum[r] - sum[i];
    w[3] = sum[n] - sum[r];
    sort(w, w + 4);
    ans = min(ans, w[3] - w[0]);
  }
  cout << ans << endl;
  return 0;
}
