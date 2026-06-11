#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
struct Edge {
  ll to;
  ll cost;
};
int main() {
  string S;
  cin >> S;
  int K;
  cin >> K;
  char ans;
  ans = S[0];
  for (int i = 1;i<K&&i<S.size(); i++) {
    if (ans != '1') break;
    ans = S[i];
    if(ans!='1')break;
  }
  cout << ans << endl;
}