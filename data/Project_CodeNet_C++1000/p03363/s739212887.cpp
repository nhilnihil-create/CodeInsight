#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

using vi=vector<int>;
using vll=vector<ll>;
using vvi=vector<vi>;

int main() {
  int N; cin >>N;
  vll A(N);
  vll B(N+1);
  rep(i,0,N) {
    cin >>A[i];
    B[i+1]=B[i]+A[i];
  }
  map<ll,ll> m;
  rep(i,0,N+1) {
    m[B[i]]++;
  }
  ll ans=0;
  for (auto p : m) {
    ll v=p.second;
    ans+=v*(v-1)/2;
  }
  cout <<ans <<endl;
  return 0;
}
