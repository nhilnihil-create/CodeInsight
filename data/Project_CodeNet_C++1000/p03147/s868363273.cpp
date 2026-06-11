#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int h[N];
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < 1000; i++) {
    int cnt = 0;
    for (int j = 1; j < N; j++) {
      if (h[j] == 0 && h[j-1] != 0) {
        cnt++;
      }
    }
    if (h[N-1] != 0) {
      cnt++;
    }
    ans += cnt;
    for (int j = 0; j < N; j++) {
      h[j] = max(h[j] - 1,0);
    }
  }
  cout << ans << endl;
  return 0;
}