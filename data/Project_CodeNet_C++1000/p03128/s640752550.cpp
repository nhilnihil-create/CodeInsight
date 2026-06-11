#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)

constexpr int MAX_N = 1e4;
int dp[MAX_N+10];
int A[9];
int main() {
  int N, M;
  ins(N, M);

  rep(i, M) {
    cin >> A[i];
    --A[i];
  }
  sort(A, A+M);
  reverse(A, A+M);
  // i本ちょうどでdp[i]桁作れる

  int cost[] = {2, 5, 5, 4, 5, 6, 3, 7, 6};
  rep(i, N+10) dp[i] = -1;
  dp[0] = 0;

  rep(i, N) {
    rep(j, M) {
      dp[i+cost[A[j]]] = max(dp[i+cost[A[j]]], dp[i] + 1);
    }
  }

  int n = N;
  rep(i, dp[N]) {
    rep(j, M) {
      if (n-cost[A[j]] >= 0 && dp[n-cost[A[j]]] + 1 == dp[n]) {
        n -= cost[A[j]];
        cout << A[j]+1;
        break;
      }
    }
    if (n == 0)
      break;
  }

  cout << endl;
  return 0;
}
