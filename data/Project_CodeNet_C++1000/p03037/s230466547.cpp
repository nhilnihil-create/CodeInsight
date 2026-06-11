#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int N, M;
  cin >> N >> M;
  
  int max_L = 1, min_R = N;
  int L, R;
  rep(i,M) {
    cin >> L >> R;
    max_L = max(max_L, L);
    min_R = min(min_R, R);
  }
  
  int ans = max(0, min_R - max_L + 1);
  cout << ans << endl;
  return 0;
}
