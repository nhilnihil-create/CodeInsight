#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)  //repマクロ

int main() {

  int32_t N, ans=0;
  int32_t A[200];
  cin >> N ;
  rep(i, N){
    cin >>A[i];
    if(A[i]%2==1){
      cout << ans << endl;
      return 0;
    }
  }
  ans=1;
  while (1) {
    rep(i,N){
      A[i]/=2;
      if(A[i]%2==1){
        cout << ans << endl;
        return 0;
      }
    }
    ans++;
  }
    cout << ans << endl;
}