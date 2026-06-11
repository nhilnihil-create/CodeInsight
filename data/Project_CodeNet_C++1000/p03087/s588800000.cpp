#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K; cin>>N>>K;
  string S; cin>>S;
  vector<int>A(N-1);
  for(int i=0;i<N-1;i++){
    if(S.at(i)=='A'&&S.at(i+1)=='C')A[i]++;
    A[i]+=A[i-1];
  }
  for(int i=0;i<K;i++){
    int a,b; cin>>a>>b;
    cout<<A[b-2]-A[a-2]<<endl;
  }
}