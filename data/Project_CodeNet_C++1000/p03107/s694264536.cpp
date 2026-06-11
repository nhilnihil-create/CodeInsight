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
  string S;
  cin >> S;
  ll ans = 0;
  REP(i, S.size() - 1) {
    if (S[i] != S[i + 1]) {
      ans += 2;
      S.erase(i, 2);
      
      i -= 1;
      if (-1 < i) i--;
    }
  }
  cout << ans << endl;
}