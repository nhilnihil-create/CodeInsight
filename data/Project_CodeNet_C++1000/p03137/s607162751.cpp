#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin >>N>>M;
  int X[M];
  for(int i=0;i<M;i++){
    cin>>X[i];
  }
  sort(X,X+M);
  int D[M-1];
  for(int i=0;i<M-1;i++){
    D[i]=X[i+1]-X[i];
  }
  sort(D,D+M-1);
  int ans=0;
  for(int i=0;i<M-N;i++){
    ans+=D[i];
  }
  cout<<ans<<endl;
    
  return 0;
}
