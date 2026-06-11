#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N,M;
  cin >> N >> M;
  int L = 1;
  int R = N;

  rep(i,M) {
    int l,r;
    cin >> l >> r;
    L = max(L,l);
    R = min(R,r);
  }

  cout << max(0, R-L+1) << endl;
  return 0;
}

// https://github.com/atcoder/live_library