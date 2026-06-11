#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, Q, Num_=0, i;
  string S;
  cin>>N>>Q>>S;
  vector<int> Num(N);
  for(i=0; i<N-1; i++){
    if(S[i]=='A' && S[i+1]=='C'){
      Num_++;
    }
    Num[i+1]=Num_;
  }

  int l, r;
  for(i=0; i<Q; i++){
    cin>>l>>r;
    cout<<Num[r-1]-Num[l-1]<<endl;
  }
  return 0;
}