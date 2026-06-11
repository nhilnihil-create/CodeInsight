#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  int a[N];
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int streak = 1;
  int ans = 0;
  for (int i = 1; i < N; i++) {
    if (a[i-1] == a[i]) {
      streak++;
    } else {
      ans += streak / 2;
      streak = 1;
    }
  }
  ans += streak / 2;
  cout << ans << endl;
  return 0;
}