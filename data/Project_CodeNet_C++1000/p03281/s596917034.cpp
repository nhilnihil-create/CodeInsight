#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define FOR(i, b, n) for (int i = b; i <= n; ++i)

using namespace std;

void solve(int N) {
  int ans(0);
  FOR(i, 1, N) {
    int n(0);
    FOR(j, 1, i) {
      if (i % j == 0)
	n++;
    }
    if (n == 8)
      ans++;
    i++;
  }
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  solve(N);

  return 0;
}
