#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<pair<ll, int>> AB(N);
  for (int i = 0; i < N; i++)
  {
    cin >> AB[i].first >> AB[i].second;
  }
  sort(AB.begin(), AB.end());
  ll ans = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++)
  {
    if (cnt + AB[i].second >= M) {
      ans += AB[i].first * (M - cnt);
      break;
    } else
    {
      cnt += AB[i].second;
      ans += AB[i].first * AB[i].second;
    }
  }
  cout << ans << endl;
  return 0;
}
