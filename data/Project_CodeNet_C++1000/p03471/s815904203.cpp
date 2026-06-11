#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N;
  int Y;

  cin >> N >> Y;

  REP(i, N+1) {
    REP(j, N+1) {
      int k = N - i - j;
      if (k >= 0 && i * 10000 + j * 5000 + k * 1000 == Y) {
        printf("%d %d %d\n", i, j, k);
        return 0;
      }
    }
  }
  cout << "-1 -1 -1";
}