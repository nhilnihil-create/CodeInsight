#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,31)-1;


int main() {
  int N; cin >> N;
  ll A[N], B[N]; rep(i,N) cin >> A[i] >> B[i];
  ll result = 0; rep(i,N) result += A[i];
  bool ok = false;
  ll mb = LLINF;
  rep(i,N) {
    if (B[i]!=A[i]) ok = true;
    if (A[i]>B[i]) mb = min(mb, B[i]);
  }
  result = (ok) ? result-mb : 0;
  cout << result << endl;
}