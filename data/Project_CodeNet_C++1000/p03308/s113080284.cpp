#include<bits/stdc++.h>
using namespace std;

int main(){
  int N,maxA=0;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(i!=j){
        maxA=max(maxA,abs(A.at(i)-A.at(j)));
      }
    }
  }
  cout << maxA << endl;
}