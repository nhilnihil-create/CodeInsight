#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  vector<ll> B(N);
  rep(i,N){
    cin >> A.at(i);
    B.at(i) = A.at(i); 
  }
  sort(B.begin(),B.end());
  ll P,Q;
  P = B.at(N/2-1);
  Q = B.at(N/2);
  rep(i,N){
    if(A.at(i) <= P){
      cout << Q << endl;
    }
    else if(A.at(i) >= Q){
      cout << P << endl;
    }
  }
  return 0;
}