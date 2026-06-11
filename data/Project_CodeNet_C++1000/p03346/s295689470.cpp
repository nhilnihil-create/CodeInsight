#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int p[N];
  int x[N];
  int a[N];
  a[0] = 1;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    p[i]--;
    x[p[i]] = i;
  }
  for (int i = 1; i < N; i++) {
    if (x[i-1] < x[i]) {
      a[i] = a[i-1] + 1;
    } else {
      a[i] = 1;
    }
  }
  int st = 0;
  for (int i = 0; i < N; i++) {
    st = max(st,a[i]);
  }
  int ans = N-st;
  cout << ans << endl;
  return 0;
}