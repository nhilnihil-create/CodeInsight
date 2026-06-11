#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

int main() {
  int N,X; cin >>N >>X;
  vector<int> m(N);
  rep(i,0,N) cin >>m[i];
  sort(m.begin(),m.end());
  int temp=accumulate(m.begin(),m.end(),0);
  int ans=N+(X-temp)/m[0];
  cout <<ans <<endl;
  return 0;
}
