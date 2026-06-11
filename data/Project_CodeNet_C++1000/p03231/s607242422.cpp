#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();

int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main() {
  int N, M;
  cin >> N >> M;
  string S, T;
  cin >> S >> T;
  int64_t g = gcd(N, M);
  int64_t L = N / g * M;
  // cout << L << endl;
  if (g == 1) {
    if (S.at(0) == T.at(0)) cout << L << endl;
    else cout << -1 << endl;
  }
  else {
  bool OK = true;
  for (int i = 0; i < L; i += L / g) {
    if (S.at(i / (L / N)) != T.at(i / (L / M))) OK = false;
    }
  if (OK) {
    cout << L << endl;
  }
  else cout << -1 << endl;
  }
  return 0;
}