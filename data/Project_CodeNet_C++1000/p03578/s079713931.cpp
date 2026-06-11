#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> D(N);
  for(int i=0; i<N; i++){
    cin >> D.at(i);
  }
  map<int, int> R;
  for(int i=0; i<N; i++){
    R[D.at(i)]++;
  }
  int M;
  cin >> M;
  vector<int> T(M);
  for(int i=0; i<M; i++){
    cin >> T.at(i);
  }
  vector<int> P(N, 0);
  int K=1;
  for(int i=0; i<M; i++){
    if(R[T.at(i)]>0){
      R[T.at(i)]--;
    }
    else{
      K=0;
      break;
    }
  }
  if(K==1){
    cout << "YES" << endl;
  }
  else{
    cout << "NO" << endl;
  }
}