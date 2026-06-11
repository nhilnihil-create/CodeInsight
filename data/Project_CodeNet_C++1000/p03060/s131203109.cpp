#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)

typedef long long Int;

int main() {
  int N;
  cin >> N;
  vector<Int> V(N), C(N);
  rep(i,N) cin >> V[i];
  rep(i,N) cin >> C[i];
  
  Int ans = 0;
  rep(i,N) {
    if (V[i] > C[i]) ans += V[i] - C[i];
  }
  
  cout << ans << endl;
}