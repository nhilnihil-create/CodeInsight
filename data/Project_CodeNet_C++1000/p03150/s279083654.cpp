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
  string key = "keyence";
  int ans = 0;
  REP(i, 7) {
    if (S[i] != key[i]) {
      break;
    }
    ans++;
  }
  for (int i = 0; i < 7;i++){
    char s = S[S.size() - 1], c = key[key.size() - 1];
    if(S[S.size()-i-1]!=key[key.size()-i-1]){
      break;
    }
    ans++;
  }
    if (7 <= ans) {
      puts("YES");
    } else {
      puts("NO");
    }
}