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
  vector <int> L(M);
  vector <int> R(M);
  rep(i,M) cin >> L[i] >> R[i];
  int ans = max(0, *min_element(all(R)) - *max_element(all(L)) + 1);
  cout << ans << endl;
  return 0;
}
