#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int N;
int a[200010], b[200010];

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
  int ans = 0;
  for (int i = 0; i+1 < 30; i++) {
    vector<int> va, vb;
    for (int j = 0; j < N; j++) {
      va.emplace_back(a[j]%(1<<(i+1)));
      vb.emplace_back(b[j]%(1<<(i+1)));
    }
    sort(vb.begin(), vb.end());
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      cnt += lower_bound(vb.begin(), vb.end(), (2*(1<<i)-va[j])) - lower_bound(vb.begin(), vb.end(), ((1<<i)-va[j]));
      cnt += lower_bound(vb.begin(), vb.end(), (4*(1<<i)-va[j])) - lower_bound(vb.begin(), vb.end(), (3*(1<<i)-va[j]));
    }
    if (cnt&1) ans += 1 << i;
  }
  cout << ans << endl;

  return 0;
}