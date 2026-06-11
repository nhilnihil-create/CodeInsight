#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,C;
  cin>>N>>M>>C;
  vector<int> B(M);
  for (int i=0; i<M; i++){
    cin>>B.at(i);
  }
  vector<vector<int>> A(N,vector<int>(M));
  vector<int> AB_sum(N,0);
  for (int i=0; i<N; i++){
    for (int j=0; j<M; j++){
      cin>>A.at(i).at(j);
      A.at(i).at(j)*=B.at(j);
      AB_sum.at(i)+=A.at(i).at(j);
    }
  }
  int count=0;
  for (int i=0; i<N; i++){
    if ((AB_sum.at(i)+C)>0){
      count++;
    }
  }
  cout<<count<<endl;
}