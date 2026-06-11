#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,K; cin >>N >>K;
  vector<int> A(N);
  rep(i,0,N) {
    cin >>A[i];
  }
  vector<int> c(N+1);
  rep(i,0,N) {
    c[A[i]]++;
  }
  sort(c.rbegin(),c.rend());
  int ans=N;
  rep(i,0,K) {
    ans-=c[i];
  }
  cout <<ans <<endl;
  return 0;
}
