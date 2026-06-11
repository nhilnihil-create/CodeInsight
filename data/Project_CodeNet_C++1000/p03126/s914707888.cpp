#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin>>N>>M;
  vector<int> food(M);
  int c=0;
  
  for(int j=0;j<N;j++){
    int K; cin>>K;
    for(int i=0;i<K;i++){
      int A; cin>>A;
      food[A-1]++;
    }
  }
  for(int k=0;k<M;k++){
    if(food[k]==N)
      c++;
  }
   
  cout<<c<<endl;
}