#include <bits/stdc++.h>
using namespace std;

int main(){
  int X,Y,Z,K; cin >> X >> Y >> Z >> K;
  vector<long long> A(X),B(Y),C(Z);
  for(int i=0; i<X; i++) cin >> A[i];
  for(int i=0; i<Y; i++) cin >> B[i];
  for(int i=0; i<Z; i++) cin >> C[i];
  
  vector<long long> D(X*Y);
  for(int i=0; i<X; i++){
    for(int j=0; j<Y; j++){
      D[i*Y+j]=A[i]+B[j];
    }
  }
  sort(D.begin(),D.end(),greater<long long>());
  D.resize(min(X*Y,K));
  
  vector<long long> E(D.size()*Z);
  for(int i=0; i<D.size(); i++){
    for(int j=0; j<Z; j++){
      E[i*Z+j]=D[i]+C[j];
    }
  }
  sort(E.begin(),E.end(),greater<long long>());
  E.resize(K);
  
  for(auto s:E) cout << s << endl;
}