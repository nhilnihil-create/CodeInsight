#include <bits/stdc++.h>
// #pragma GCC optimize ("O3")
// #pragma GCC target ("sse4")
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)

#define pb push_back
#define mp make_pair
#define st first
#define nd second

const int MOD = 1000000007;

char S[1000];
int DP[400][400][400];

int main() {
  // ios_base::sync_with_stdio(0);

  int K;
  scanf("%s%d", S, &K);
  int N = strlen(S);
  FORD(i,N,0)FOR(j,i+1,N+1)REP(k,K+1) {
    if (j == i+1) {
      DP[i][j][k] = 1;
      continue;
    }
    DP[i][j][k] = max(DP[i][j-1][k], DP[i+1][j][k]);
    if (S[i] == S[j-1]) DP[i][j][k] = max(DP[i][j][k], DP[i+1][j-1][k] + 2);
    if (k > 0) DP[i][j][k] = max(DP[i][j][k], DP[i+1][j-1][k-1] + 2);
  }

  printf("%d\n", DP[0][N][K]);
}
