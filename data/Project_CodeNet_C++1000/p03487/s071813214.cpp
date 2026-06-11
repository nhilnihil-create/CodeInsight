#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll a[N];
  ll ans = 0;
  ll num[100001];
  for (int i = 0; i <= 100000; i++) {
    num[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (a[i] > 100000) {
      ans++;
    } else {
      num[a[i]]++;
    }
  }
  for (int i = 1; i <= 100000; i++) {
    if (num[i] < i) {
      ans += num[i];
    } else {
      ans += num[i] - i;
    }
  }
  cout << ans << endl;
  return 0;
}