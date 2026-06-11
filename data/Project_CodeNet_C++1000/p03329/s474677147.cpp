#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> oprt(10*N,N);
  oprt.at(0) = 0;
  for(int i=0; i<=N; i++){
    oprt.at(i+1) = min(oprt.at(i+1), oprt.at(i)+1);
    for(int j=6; i+j<=N; j*=6){
      oprt.at(i+j) = min(oprt.at(i+j), oprt.at(i)+1);
      for(int k=9; i+k<=N; k*=9){
        oprt.at(i+k) = min(oprt.at(i+k), oprt.at(i)+1);
        oprt.at(i+j+k) = min(oprt.at(i+j+k), oprt.at(i+j)+1);
      }
    }
  }
  cout << oprt.at(N);
  return 0;
}