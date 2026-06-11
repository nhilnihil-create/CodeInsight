#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<vector<int>> vec(N,vector<int>(3));
  for(int i=0; i<N; i++){
    for(int j=1; j<3; j++){
      cin >> vec.at(i).at(j);
    }
    vec.at(i).at(0) = vec.at(i).at(1) + vec.at(i).at(2);
  }
  sort(vec.rbegin(),vec.rend());
  
  int64_t takahashi = 0;
  int64_t aoki = 0;
  for(int i=0; i<N; i++){
    if(i %2 == 0){
      takahashi += vec.at(i).at(1);
    }
    else{
      aoki += vec.at(i).at(2);
    }
  }
  cout << takahashi - aoki << endl;
}