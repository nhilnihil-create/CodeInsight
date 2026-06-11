#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, K;
  cin >> N >> K;
  vector <int> h(N);
  rep(i,N) cin >> h[i];
  sort(all(h));
  int ans = inf;
  rep(i,N - K + 1){
    ans = min(ans, h[i + K - 1] - h[i]);
  }
  cout << ans << endl;
  return 0;
}
