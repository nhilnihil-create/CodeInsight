#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i=0;i<N;i++){
    cin >> S.at(i);
  }
  int p = 1, F = 0;
  for (int i=0;i<N;i++){
    p = 1;
    for (int j=0;j<N;j++){
      for (int k=0;k<N;k++){
        if (S.at((j+i)%N).at(k) != S.at((k+i)%N).at(j)){
          p = 0;
          break;
        }
      }
      if (p == 0){
        break;
      }
    }
    F += N * p;
  }
  cout << F << endl;
  return 0;
}