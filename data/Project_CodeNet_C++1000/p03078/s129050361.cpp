#include <bits/stdc++.h>
using namespace std;

int main(){
  #define int int64_t
  int X,Y,Z,K;
  cin>>X>>Y>>Z>>K;
  vector<int> A(X);
  vector<int> B(Y);
  vector<int> C(Z);
  vector<int> V;
  for(int i=0;i<X;++i){
    scanf("%lld",&A.at(i));
  }for(int i=0;i<Y;++i){
    scanf("%lld",&B.at(i));
  }for(int i=0;i<Z;++i){
    scanf("%lld",&C.at(i));
  }
  sort(A.begin(),A.end());
  sort(B.begin(),B.end());
  sort(C.begin(),C.end());
  reverse(A.begin(),A.end());
  reverse(B.begin(),B.end());
  reverse(C.begin(),C.end());
  for(int i=0;i<X;++i){
    for(int j=0;j<Y;++j){
      for(int k=0;k<Z;++k){
        if((i+1)*(j+1)*(k+1)<=K){
          V.emplace_back(A.at(i)+B.at(j)+C.at(k));
        }
      }
    }
  }
  sort(V.begin(),V.end());
  reverse(V.begin(),V.end());
  for(int i=0;i<K;++i){
    printf("%lld\n",V.at(i));
  }
}
