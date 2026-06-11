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
  
  vector<Int> BtoA(N,0), BtoC(N,0);
  
  rep(i,N) {
    auto ite = lower_bound(A.begin(),A.end(),B[i]);
    BtoA[i] = ite - A.begin();
  }
  
  rep(i,N) {
    auto ite = upper_bound(C.begin(),C.end(),B[i]);
    BtoC[i] = C.end() - ite;
  }
  

  Int ans = 0;
  rep(i,N) {
    ans += BtoA[i] * BtoC[i];
  }
  
  cout << ans << endl;

}