#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,M,C,count=0;
  cin >> N >> M >> C;
  vector<int> B(M);
  vector<vector<int>> A(N,vector<int>(M));
  for(int i=0;i<M;i++){
    cin >> B.at(i);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      cin >> A.at(i).at(j);
    }
  }
  for(int i=0;i<N;i++){
    int sum=C;
    for(int j=0;j<M;j++){
      sum+=A.at(i).at(j)*B.at(j);
    }
    if(sum>0){
      count++;
    }
  }
  cout << count << endl;
}
  