#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

bool pairCompare(const P& firstElof, const P& secondElof){
  return firstElof.first > secondElof.first;
}

int main() {
  int N,M;
  cin >> N >> M;
  vector<ll> A(N);
  rep(i,N){
    int a;
    cin >> a;
    A.at(i) = a;
  }
  
  vector<P> X(M);
  rep(i,M){
    int b,c;
    cin >> b >> c;
    X.at(i) = make_pair(c,b);
  }

  sort(A.begin(), A.end(), greater<ll>());
  sort(X.begin(), X.end(), pairCompare);
 
  ll ans = 0;
  int aind = 0;
  int xind = 0;
  rep(i,N){
    if (A[aind] >= X[xind].first) {
      ans += A[aind];
      aind++;
    } else {
      ans += X[xind].first;
      X[xind].second--;
      if (X[xind].second == 0) {
        xind++;
      }
    }
    //cout << i << " : " << ans << endl;
  }

  cout << ans << endl;
  return 0;
}
