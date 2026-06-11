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
  vector <int> X(M);
  rep(i,M) cin >> X[i];
  sort(all(X));
  if (N >= M) cout << 0 << endl;
  else{
    vector <int> sa(M - 1);
    rep(i,M - 1) sa[i] = X[i + 1] - X[i];
    sort(sa.rbegin(), sa.rend());  //降順
    int sum = 0;
    rep(i,N - 1) sum += sa[i];
    int ans = X[M - 1] - X[0] - sum;
    cout << ans << endl;
  }
  return 0;
}
