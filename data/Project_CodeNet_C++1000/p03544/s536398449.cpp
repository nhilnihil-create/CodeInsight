#include <bits/stdc++.h>
using namespace std;

int64_t lucas(int64_t N);

int main(){
  int N;
  cin >> N;
  
  vector<int64_t> lucas = {2, 1};
  
  for(int i = 0; i < N - 1; i++){
    lucas.push_back(lucas[i] + lucas[i+1]);
  }
  
  cout << lucas[N] <<endl;
}

int64_t lucas(int64_t N){
  if(N == 0)
    return 2;
  if(N == 1)
    return 1;
  
  int64_t L;
  L = lucas(N-1) + lucas(N-2);
  return L;
}