#include<bits/stdc++.h>
using namespace std;
int main(){
  int N; cin>>N;
  vector<string> S(N);
  vector<int> A(N,0);
  int K=0;
  for(int i=0; i<N; i++){
    cin>>S.at(i);
    A[i]+=(S[i].size()-1);
  }
  for(int i=0; i<N-1; i++){
    if(S[i].at(A[i])!=S[i+1].at(0))
      K++;
    else continue;
  }
  sort(S.begin(),S.end());
  for(int i=0; i<N-1; i++){
    if(S[i]==S[i+1])
      K++;
    else continue;
  }
  if(K==0)
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}