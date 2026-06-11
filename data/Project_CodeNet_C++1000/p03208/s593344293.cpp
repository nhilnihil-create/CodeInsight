#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N,K; cin >>N >>K;
  vector<int> h(N);
  rep(i,0,N) {cin >>h[i];}
  sort(h.begin(),h.end());
  vector<int> a;
  rep(i,0,N-K+1) {
    a.push_back(h[i+K-1]-h[i]);
  }
  cout <<*min_element(a.begin(),a.end()) <<endl;
  return 0;
}
