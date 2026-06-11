#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int>UE(N);
  vector<int>ST(N);
  vector<int>UES(N);
  vector<int>STS(N);
  vector<int>Ans(N);
  for(int i=0;i<N;i++){
    cin>>UE[i];
    if(i==0){
      UES[i]=UE[i];
    }
    else{
      UES[i]=UES[i-1]+UE[i];
    }
  }
  for(int i=0;i<N;i++){
    cin>>ST[i];
    if(i==0){
      STS[i]=ST[i];
    }
    else{
      STS[i]=STS[i-1]+ST[i];
    }
  }
  Ans[0]=UES[0]+STS[N-1];
  for(int i=1;i<N;i++){
    Ans[i]=UES[i]+STS[N-1]-STS[i-1];
  }
  sort(Ans.begin(),Ans.end());
  cout<<Ans[N-1]<<endl;
}
  
  
  
