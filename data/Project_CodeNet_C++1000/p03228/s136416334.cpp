#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int A,B,K; cin >>A >>B >>K;
  rep_eq(i,1,K) {
    if (i%2==1) {
      A/=2;
      B+=A;
    } else {
      B/=2;
      A+=B;
    }
  }
  cout <<A <<" " <<B <<endl;
  return 0;
}
