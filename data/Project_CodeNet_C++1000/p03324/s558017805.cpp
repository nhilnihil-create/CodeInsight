#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int D,N; cin >>D >>N;
  int temp=pow(100,D);
  if (N<=99) cout <<temp*N <<endl;
  else cout <<temp*101 <<endl;
  return 0;
}
