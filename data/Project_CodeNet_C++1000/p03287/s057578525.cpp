#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  long long N, M;
  long long A[100100];
  cin >> N >> M;
  REP(i, N) cin >> A[i];

  long long s[N + 1];
  REP(i, N+1) s[i] = 0;
  REP(i, N) s[i+1] = s[i] + A[i];
  REP(i, N+1) s[i] %= M;
  // REP(i, N+1) cout << s[i] << ' ';
  // cout << endl;

  long long ans = 0;

  map<long long, long long> dct;
  REP(i, N+1) dct[s[i]]++;
  for(auto itr = dct.begin(); itr != dct.end(); itr++) {
    ans += (itr->second - 1) * itr->second / 2;
  }
  cout << ans << endl;

  return 0;
}