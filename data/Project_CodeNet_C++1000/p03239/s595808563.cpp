#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N>>T;
  vector<int>c(N);
  vector<int>t(N);
  int ans=0;
  bool A=false;
  for(int i=0;i<N;i++){
    cin>>c[i]>>t[i];
    if(t[i]<=T){
      if(ans==0){
        ans=c[i];
        A=true;
      }
      else{
        ans=min(ans,c[i]);
      }
    }
  }
  if(A==false){
    cout <<"TLE"<<endl;
  }
  else{
    cout<<ans<< endl;
  }
}