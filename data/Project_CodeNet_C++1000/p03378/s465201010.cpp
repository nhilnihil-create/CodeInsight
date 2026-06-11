#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

using namespace std;

typedef long long ll;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,m,x; cin>>n>>m>>x;
  int as[n+1];
  
  int to0 = 0;
  int toN = 0;
  
  rep(i,n+1) {
    as[i] = 0;
  }
  
  rep(i,m) {
    int a; cin>>a;
    as[a] = 1;
  }
  
  for (int i = x; i >= 0; --i) {
    to0 += as[i];
  }
  
  for (int i = x; i <= n; ++i) {
    toN += as[i];
  }
  
  cout<<min(to0, toN);
  
  return 0;
}