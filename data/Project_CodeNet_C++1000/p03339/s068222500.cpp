#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  vector<int>W(N,0);
  if(S.at(0)=='W'){
    W[0]=1;
  }
  for(int i=1;i<N;i++){
    if(S.at(i)=='W'){
      W[i]=W[i-1]+1;
    }
    else{
      W[i]=W[i-1];
    }
  }
  vector<int>Ans(N);
  Ans[0]=N-1-(W[N-1]-W[0]);
  for(int i=1;i<N;i++){
    Ans[i]=W[i-1]+N-i-1-(W[N-1]-W[i]);
  }
  sort(Ans.begin(),Ans.end());
  cout<<Ans[0]<<endl;
}
    
