#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,M,X;
  cin >> N >> M >> X;
  vector<int> data(M);
  for(int i=0; i<M; i++){
    cin >> data[i];
  }
  int sum1=0,sum2=0;
  for(int i=X; i>0; i--){
    for(int j=0; j<M; j++){
      if(data[j]==i){
        sum1++;
      }
    }
  }
  for(int i=X; i<N+1; i++){
    for(int j=0; j<M; j++){
      if(data[j]==i){
        sum2++;
      }
    }
  }
  cout << min(sum1,sum2) << endl;
  
}