#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  int A[N+1]={}; rep(i,N) cin >> A[i];
  ll result = 0;
  rep(i,N+1) {
    // cout << i << " " << result << endl;
    if (i==0) {
      if (A[i]==0) continue;
      else { result = -1; break; }
    }
    if (A[i]-A[i-1]==1) continue;
    if (A[i-1]>=A[i]) { result += A[i-1]; continue; }
    result = -1; break;
  }
  cout << result << endl;
  return 0;
}