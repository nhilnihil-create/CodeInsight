#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<int> A(1 * 1e5 + 1000, 0), B(1 * 1e5 + 1000, 0);
  char c = S[0];
  int num = 0, id1 = 0;
  REP(i, N) {
    if (c != S[i]) {
      if (c == '1') {
        A[id1] = num;
        num = 0;
        id1++;
      } else {
        B[id1] = num;
        num = 0;
        id1++;
      }
      c = S[i];
    }
    num++;
  }
  if (c == '1') {
    A[id1] = num;
  } else {
    B[id1] = num;
  }
  ll ans = 0;
  num = 0;
  int one = 0, l = 0;
  for (int i = 0; i < N; i++ && one <= K) {
    if (B[i] != 0) {
      if (one >= K) break;
      one++;
    }
    num += A[i] + B[i];
    l = i;
  }
  ans = max<ll>(num, ans);
  int r = 0;
  for (int i = l + 1; i <= N; i++) {
    if (A[r] != 0) {
      num -= B[r] + A[r];
      r++;
    }
    num -= B[r] + A[r];
    r++;
    if (B[i] != 0) {
      num += B[i] + A[i];
      i++;
    }
    num += B[i] + A[i];
    ans = max<ll>(ans, num);
  }
  cout << ans << endl;
}