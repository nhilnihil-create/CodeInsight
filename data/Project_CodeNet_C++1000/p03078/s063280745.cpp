#include<bits/stdc++.h>
using namespace std;

int main(){
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<long long> A(X);
  vector<long long> B(Y);
  vector<long long> C(Z);
  for (int i=0;i<X;i++){
    cin >> A.at(i);
  }
  for (int i=0;i<Y;i++){
    cin >> B.at(i);
  }
  for (int i=0;i<Z;i++){
    cin >> C.at(i);
  }
  vector<long long> F(X*Y);
  for (int i=0;i<X;i++){
    for (int j=0;j<Y;j++){
      F.at(i*Y+j) = A.at(i) + B.at(j);
    }
  }
  sort(F.begin(), F.end());
  reverse(F.begin(), F.end());
  int M = min(X*Y, K);
  vector<long long> G(M*Z);
  for (int i=0;i<M;i++){
    for (int j=0;j<Z;j++){
      G.at(i*Z+j) = F.at(i) + C.at(j);
    }
  }
  sort(G.begin(), G.end());
  reverse(G.begin(), G.end());
  for (int i=0;i<K;i++){
    cout << G.at(i) << endl;
  }
  return 0;
}