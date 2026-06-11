#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M;
  cin>>N>>M;
  vector<multiset<int>> A(N);
  for (int i=0; i<N; i++){
    int K;
    cin>>K;
    for (int j=0; j<K; j++){
      int Aj;
      cin>>Aj;
      A.at(i).insert(Aj);
    }
  }
  int total_count=0;
  for (int j=1; j<=M; j++){
    int count=0;
    for (int i=0; i<N; i++){
      if (A.at(i).find(j)!=A.at(i).end()){
        count++;
      }
    }
    if (count==N){
      total_count++;
    }   
  }
  cout<<total_count<<endl;
}
  