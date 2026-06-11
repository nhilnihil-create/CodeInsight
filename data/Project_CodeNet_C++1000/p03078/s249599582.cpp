#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int X,Y,Z,K;cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  for(int i=0;i<X;i++){
    cin >> A[i];
  }
  for(int i=0;i<Y;i++){
    cin >> B[i];
  }
  for(int i=0;i<Z;i++){
    cin >> C[i];
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  sort(B.begin(),B.end());
  reverse(B.begin(),B.end());
  sort(C.begin(),C.end());
  reverse(C.begin(),C.end());
  vector<ll> D;
  for(int i=0;i<min(K,X);i++){
    for(int j=0;j<min(K,Y);j++){
      D.push_back(A[i]+B[j]);
    }
  }
  sort(D.begin(),D.end());
  reverse(D.begin(),D.end());
  vector<ll> E;
  int W = D.size();
  for(int i=0;i<min(K,Z);i++){
    for(int j=0;j<min(K,W);j++){
      E.push_back(C[i]+D[j]);
    }
  }
  sort(E.begin(),E.end());
  reverse(E.begin(),E.end());
  for(int i=0;i<K;i++){
    cout << E[i] << endl;
  }
}