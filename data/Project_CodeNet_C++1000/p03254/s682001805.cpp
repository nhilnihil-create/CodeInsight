#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  ll x;
  cin >> N >> x;
  ll a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a,a+N);
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (x >= a[i]) {
      ans++;
      x -= a[i];
    }
  }
  if (x != 0 && ans == N) {
    ans--;
  }
  cout << ans << endl;
  return 0;
  
}
