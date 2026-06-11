#include <bits/stdc++.h>
using namespace std;
 
int main() {
int N,K;
  cin >> N >> K;
vector<int> data(N);
  for(int i=0;i < N;i++){
  cin >> data.at(i);
  }
  if(N%(K-1) == 0){
  if(K == 2){
  cout << N-1;
  }
  else{
  cout << N/(K-1);
  }
  }
  else if(N%(K-1) == 1){
  cout << N/(K-1);
  }
  else{
  cout << N/(K-1)+1;
  }
}