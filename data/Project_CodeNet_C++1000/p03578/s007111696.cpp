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
  int N;
  cin >> N;
  unordered_map<int, int> D{};
  REP(i, N) {
    int a;
    cin >> a;
    D[a]++;
  }
  int M;
  cin >> M;
  bool ok = true;
  REP(i, M) { int a;
    cin >> a;
    if (D[a] <= 0) ok = false;
    D[a]--;
  }
  puts(ok?"YES":"NO");
  cout << "\n\n";
}