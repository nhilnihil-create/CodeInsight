#include<bits/stdc++.h>
using namespace std;

int main(){
  
  long long N, i, l, r;
  cin>>N;
  vector<long long> X(N), Xs(N);
  for(i=0;i<N;i++){
    cin>>X[i];
    Xs[i] = X[i];
  }
  sort(Xs.begin(), Xs.end());
  l=Xs[N/2-1];r=Xs[N/2];
  for(i=0;i<N;i++){
    if(l>=X[i]){
      cout<<r<<endl;
    }else if(r<=X[i]){
      cout<<l<<endl;
    }
  }
  return 0;
}