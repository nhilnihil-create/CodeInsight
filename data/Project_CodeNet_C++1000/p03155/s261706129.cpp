#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void solve(long long N, long long H, long long W) {
  int h = max(0ll, (N-H+1));
  int w = max(0ll, (N-W+1));
  cout << h * w << endl;

}

int main() {

  long long N;
  scanf("%lld", &N);
  long long H;
  scanf("%lld", &H);
  long long W;
  scanf("%lld", &W);
  solve(N, H, W);
  return 0;
}
