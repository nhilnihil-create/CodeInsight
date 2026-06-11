#include<bits/stdc++.h>
using namespace std;

int main(){
  int64_t D, G;
  cin >> D >> G;
  vector<int64_t> P(D), C(D);
  for(int64_t i=0; i<D; i++){
    cin >> P.at(i) >> C.at(i);
  }
  int64_t Ans=10000;
  for(int64_t i=0; i<(int64_t)pow(2, D); i++){
    int64_t subAns=0;
    vector<int64_t> V(D, 0);
    int64_t k=i;
    for(int64_t j=0; j<D; j++){
      if(k%2==1){
        V.at(j)=1;
      }
      k/=2;
    }
    int64_t Sum=0;
    int64_t L=0;
    for(int64_t j=0; j<D; j++){
      L+=V.at(j)*P.at(j);
      Sum+=V.at(j)*(100*(1+j)*P.at(j)+C.at(j));
    }
    if(Sum>=G){
      subAns=L;
    }
    else{
      for(int64_t j=D-1; j>=0; j--){
        if(V.at(j)==0){
          if(Sum+100*(1+j)*(P.at(j)-1)<G){
            goto finish;
          }
          else{
            L+=(G-Sum-1)/(100*(1+j))+1;
            subAns=L;
            break;
          }
        }
      }
    }
    Ans=min(subAns, Ans);
finish: L=0;
  }
  cout << Ans << endl;
}
