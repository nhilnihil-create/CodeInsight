#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, M;
  cin >> N >> M;

  int A, B, C;
  map<int,int,greater<int>> d;

  rep(i,N) {
    cin >> A;
    d[A]++;
  }

  rep(i,M) {
    cin >> B >> C;
    d[C] += B;
  }

  ll num = 0, ans = 0;
  for (auto c: d) {
    ll value = c.first;
    ll count = c.second;
    if (num + count > N) {
      ans += value * (N - num);
      break;
    }
    ans += value * count;
    num += count;
  }

  cout << ans << endl;
  return 0;
}
