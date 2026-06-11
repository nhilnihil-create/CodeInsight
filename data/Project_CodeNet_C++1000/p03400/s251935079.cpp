#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,D,X; cin >>N >>D >>X;
  vector<int> A(N);
  rep(i,0,N) cin >>A[i];
  int ans=X;
  rep(i,0,N) ans+=1+(D-1)/A[i];
  cout <<ans <<endl;
}
