#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;
using ll=int64_t;

int main() {
  int N,M; cin >>N >>M;
  vector<pair<int,int>> AB(N);
  rep(i,0,N) {
    cin >>AB[i].first >>AB[i].second;
  }
  sort(AB.begin(),AB.end());
  ll ans=0;
  rep(i,0,N) {
    if (M>=AB[i].second) {
      M-=AB[i].second;
      ans+=ll(AB[i].first)*ll(AB[i].second);
  } else {
      ans+=ll(M)*ll(AB[i].first);
      M=0;
    }
  }
  cout <<ans <<endl;
  return 0;
}
