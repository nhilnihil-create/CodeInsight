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
  int mn = INF;
  REP(i, S.size() - 2) {
    int num = (S[i] - '0') * 100 + (S[i + 1] - '0') * 10 + S[i + 2]-'0';
    mn = min(mn, abs(753-num));
  }
  cout << mn << endl;
}