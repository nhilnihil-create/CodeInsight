#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,M;
  cin >> N >> M;
  vector<P> Hate(M);
  if (N == 2 && M == 1) {
    cout << 1 << endl;
    return 0;
  }
  for (int i = 0; i < M; i++) {
    cin >> Hate[i].first >> Hate[i].second;
    Hate[i].first--;
    Hate[i].second--;
  }
  sort(Hate.begin(),Hate.end());

  int ans = 0;
  int cnt = 0;
  int m = 999999;
  for (int i = 0; i < N; i++) {
    while (Hate[cnt].first == i) {
      m = min(m,Hate[cnt].second);
      cnt++;
    }
    if (i == m - 1) {
      ans++;
      m = 999999;
    }
  }
  cout << ans << endl;
  return 0;
}