#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,K; cin >>N >>K;
  int a=(N+1)/2;
  cout <<(a>=K ? "YES":"NO") <<endl;
  return 0;
}
