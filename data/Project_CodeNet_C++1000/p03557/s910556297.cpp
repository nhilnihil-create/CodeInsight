#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){ 
  Int N;
  cin >> N;
  vector<Int> A(N), B(N), C(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) cin >> C[i];
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  
  vector<Int> AtoB(N,0), BtoC(N,0), BtoC2(N+1,0);
  
  rep(i,N) {
    auto ite = upper_bound(B.begin(),B.end(),A[i]);
    AtoB[i] = ite - B.begin();
  }
  
  rep(i,N) {
    auto ite = upper_bound(C.begin(),C.end(),B[i]);
    BtoC[i] = C.end() - ite;
  }
  
  BtoC2[N-1] = BtoC[N-1];
  rep1(i,N-1) {
    BtoC2[N-1-i] = BtoC2[N-i] + BtoC[N-1-i];
  }
  
  Int ans = 0;
  rep(i,N) {
    ans += BtoC2[AtoB[i]];
  }
  
  cout << ans << endl;

}