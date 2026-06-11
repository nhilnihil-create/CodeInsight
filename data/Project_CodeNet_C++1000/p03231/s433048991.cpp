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
  bool flag = true;
  for (int k = 0; k < g; k++) {
    if (S.at(k * N / g) != T.at(k * M / g)) {
      flag = false;
    } 
  }
  if (flag) cout <<  N / g * M << endl;
  else cout << -1 << endl;
  return 0;
}