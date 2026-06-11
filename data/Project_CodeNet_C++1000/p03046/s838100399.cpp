#include<bits/stdc++.h>
using namespace std;
int main(){
  int N, K;
  cin >> N >> K;
  N = pow(2,N);
  /*vector<int> vec(N*2);
  for(int i=0; i<N; i++){
    vec.at(i) = i;
    vec.at(N+i) = i;
  }
  sort(vec.begin(),vec.end());
  do{
    bool flag = true;
    for(int i=0; i<N; i++){
      bool seen = false;
      int x = i;
      for(int j=0; j<N*2; j++){
        if(!seen && vec.at(j) == i){
          seen = true;
          continue;
        }
        if(seen){
          x ^= vec.at(j);
          if(vec.at(j) == i){
            if(x != K){
              flag = false;
            }
          }
        }
      }
    }
    if(flag){
      for(int i=0; i<2*N; i++){
        cout << vec.at(i) << " ";
      }
      cout << endl;
    }
  }while(next_permutation(vec.begin(),vec.end()));*/
  if(K == 0){
    for(int i=0; i<N; i++){
      cout << i << endl;
      cout << i << endl;
    }
  }
  else if(K >= N || (K == 1 && N == 2)){
    cout << -1 << endl;
  }
  else{
    vector<int> vec(0);
    for(int i=1; i<N; i++){
      if(i == K){
        continue;
      }
      else{
        vec.push_back(i);
      }
    }
    cout << 0 << endl;
    cout << K << endl;
    cout << 0 << endl;
    for(int i=0; i<N-2; i++){
      cout << vec.at(i) << endl;
    }
    cout << K << endl;
    reverse(vec.begin(),vec.end());
    for(int i=0; i<N-2; i++){
      cout << vec.at(i) << endl;
    }
  }
}