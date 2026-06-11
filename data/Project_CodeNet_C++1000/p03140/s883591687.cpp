#include <iostream>
using namespace std;

#define out(v) cout<<v<<"\n"
#define rep(i,n) for(int i=0;i<(n);++i)
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; cin >> N;
  string A, B, C;
  cin >> A >> B >> C;

  int ans = 0;
  rep(i, N) {
    if (A[i] == B[i] && B[i] == C[i])
      continue;
    if (A[i] == B[i] || B[i] == C[i] || A[i] == C[i])
      ++ans;
    else
      ans += 2;
  }
  out(ans);

  return 0;
}
