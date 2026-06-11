#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  vector<int>P(N),I(N);
  for(int i=0;i<N;i++){
    cin>>P[i];P[i]--;I[P[i]]=i;
  }
  int M=0,tmp=1;
  for(int i=0;i<N;i++){
    if(i==N-1||I[i+1]<I[i]){M=max(M,tmp);tmp=1;}
    else tmp++;
  }
  cout<<N-M;
}

