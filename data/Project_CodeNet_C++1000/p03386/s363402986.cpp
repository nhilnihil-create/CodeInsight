#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int A,B,K; cin >>A >>B >>K;
  rep_eq(i,A,min(B,A+K-1)) cout <<i <<endl;
  rep_eq(i,max(B-K+1,A+K),B) cout <<i << endl;
  return 0;
}
