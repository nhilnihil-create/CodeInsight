#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N), counter(N,0);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
    counter.at(A.at(i)-1)++;
  }
  sort(counter.begin(),counter.end());
  int num_ball = 0;
  for(int i=N-1; i>N-1-K; i--){
    num_ball += counter.at(i);
  }
  cout << N - num_ball;
  return 0;
}