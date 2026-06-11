#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<pair<int, int>> itv(M);
  rep (i, M) {
    int a, b;
    cin >> a >> b;
    pair<int, int> p(b, a);
    itv[i] = p;
  }
  
  sort(itv.begin(), itv.end());
  
  int start = 0;
  int res = 0;
  for (int i = 0; i < M; i++) {
    if (itv[i].second >= start) {
      res ++;
      start = itv[i].first;
    }
  }
  
  cout << res << endl;
}