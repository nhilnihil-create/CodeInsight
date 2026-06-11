#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,M,C;
  cin>>N>>M>>C;
  vector<int> B(M);
  for(int i=0;i<M;i++){
  cin>>B.at(i);
  }
  vector<vector<int>> A(N,vector<int>(M));
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin>>A.at(i).at(j);
    }
  }
  int count_ans=0;
  for(int i=0;i<N;i++){
    int count_judge=C;
    for(int j=0;j<M;j++){
      count_judge+=A.at(i).at(j)*B.at(j);
    }
      if(count_judge>0){
      count_ans++;
      }
  }
  cout<<count_ans<<endl;
}