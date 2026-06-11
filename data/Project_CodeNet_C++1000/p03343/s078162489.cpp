#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int N, K, Q; cin >> N >> K >> Q;
  vector<int> A(N); rep(i, N) cin >> A[i];
  vector<int> As(A);

  sort(As.begin(), As.end());
  const int INF = 1e9 + 10;
  int ans = INF;

  rep(minnum, N) {
    int minA = As[minnum];
    vector<vector<int>> vv(1);
    int v = 0;
    rep(i, N) {
      if (A[i] < minA) {
        vv.push_back(vector<int>());
        v++;
      } else {
        vv[v].push_back(A[i]);
      }
    }
    vector<int> vec;
    for (auto& x : vv) {
      sort(x.begin(), x.end());
      rep(k, x.size() - K + 1) vec.push_back(x[k]);
    }
    sort(vec.begin(), vec.end());
    if(vec.size() < Q) continue;
    ans = min(ans, vec[Q - 1] - vec[0]);
  }
  cout << ans << endl;
}
