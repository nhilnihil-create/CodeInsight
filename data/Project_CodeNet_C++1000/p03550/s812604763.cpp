#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

int main(){
   Int N, Z, W; cin >> N >> Z >> W;
   vector<Int> A(N);
   rep(i,N) cin >> A[i];

   if(N == 1){
       cout << abs(A[0] - W) << endl;
   } else {
       cout << max(abs(A[N-1]-A[N-2]), abs(A[N-1]-W)) << endl;
   }
}
