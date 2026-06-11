#include <bits/stdc++.h>
using namespace std;
int main(){
  int M,N;
  cin>>M>>N;
  vector<pair<pair<int,int>,int>> A(N);
  for(int i=0;i<N;i++){
    cin>>A[i].first.second>>A[i].first.first;
    A[i].second=i;
  }
  sort(A.begin(),A.end());
  vector<int> B(M+1,1),C(N),D(N);
  for(int i=0;i<N;i++){
    C[A[i].second]=B[A[i].first.second];
    B[A[i].first.second]++;
    D[A[i].second]=A[i].first.second;
  }
  for(int i=0;i<N;i++){
    for(int j=to_string(D[i]).size();j<6;j++)
      cout<<0;
    cout<<D[i];
    for(int j=to_string(C[i]).size();j<6;j++)
      cout<<0;
    cout<<C[i]<<endl;
  }
}
