#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int B[N+1]={};
  int W[N+1]={};
  int temp=0;
  B[0]=0;

  for(int i=0;i<N;i++){
    if(S.at(i)=='#'){
      temp++;
    }
    B[i+1]=temp;
  }
  temp=0;
  for(int i=N-1;i>=0;i--){
    if(S.at(i)=='.'){
      temp++;
    }
    W[i]=temp;
  }  
  W[N+1]=0;
  int ans=1000000000;
  for(int i=0;i<N;i++){
    ans=min(ans,B[i]+W[i+1]);
    //cout<<i<<" "<<B[i]<<" "<<W[i+1]<<endl;
  }
  cout<<ans<<endl;
  return 0;
}

  