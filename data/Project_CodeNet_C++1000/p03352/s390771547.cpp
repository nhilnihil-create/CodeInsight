#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  int X;
  cin >> X;
  ll ans = 0;
  P n ;
  for (int i = 1; i < 1001; i++) {
    for (int j = 2; j <= 10; j++) {
      ll num = pow(i, j);
      if(num<=X&&ans<=num){
        n=P(i, j);
        ans = max(ans, num);
      }
    }
  }
  cout << pow(n.first,n.second) << endl;
}