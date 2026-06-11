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
  int S, X;
  cin >> S;
  
  REP(i, 100000) {
    if (S == 4 || S == 2 || S == 1) {
      cout << i + 4 << endl;
      return 0;
    }
    if (S % 2 == 0) {
      S = S/2;
    } else {
      S = 3*S + 1;
    }
  }
  return 0;
}