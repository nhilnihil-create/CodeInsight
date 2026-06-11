#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;cin>>N;
  int M;cin>>M;
  vector<int> X(M);
  vector<int> L(M-1);
  for(int i=0;i<M;i++)cin>>X[i];
  sort(X.begin(),X.end());
  int ans=0;
  if(N>=M){
    ans=0;
  }else{
  	for(int i=0;i<M-1;i++){
      L[i]=X[i+1]-X[i];
    }
    sort(L.begin(),L.end());
    for(int i=0;i<M-N;i++){
      ans+=L[i];
    }
  }
  cout<<ans<<endl;
}
