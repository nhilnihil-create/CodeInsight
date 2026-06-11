#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, M;
  cin >> N >> M;
  //vector <int> A(N);
  //vector <int> B(N);
  vector <P> p(N);
  rep(i,N) cin >> p[i].first >> p[i].second;
  sort(all(p));
  ll ans = 0;  //必要なお金
  for (int i = 0; i < N; i++){
    //この店で購入する本数
    ll buy = min(M, p[i].second);
    ans += buy * p[i].first;
    M -= buy;
  }
  cout << ans << endl;
  return 0;
}
