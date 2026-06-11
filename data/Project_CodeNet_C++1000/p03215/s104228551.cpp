#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define REP(i,n) for(int i=0;i<n;i++)

int N, K;
ll A[1001];

int main() {
  cin >> N >> K;
  REP(i,N) cin >> A[i];
  vector<ll> B, C;
  REP(i,N) {
    REP(j, B.size()) {
      B[j] += A[i];
    }
    B.push_back(A[i]);
    copy(B.begin(),B.end(),back_inserter(C));
  }

  ll x = 0;
  int m = 40;
  for (int i = m; i >= 1; i--) {
    int cnt = 0;
    REP(j, C.size()) {
      if (((x|(1LL<<(i-1))) & C[j]) == (x|(1LL<<(i-1)))) cnt++;
    }
    if (cnt >= K) x |= (1LL<<(i-1));
  }

  cout << x << endl;
  
  return 0;
}
