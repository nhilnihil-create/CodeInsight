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
int f(int x){
  if (x % 2 == 0) return x / 2;
  return 3 * x + 1;
}
int main() {
  int s;
  cin >> s;
  map<int, int> A{};
  A[s] = 1;
  int i = 1;
  while(true){
    i++;
    int news=f(s);
    if(A[news]==1){
      cout << i << endl;
      return 0;
    }
    s = news;
    A[news] = 1;
  }
}