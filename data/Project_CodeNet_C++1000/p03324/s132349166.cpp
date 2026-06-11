#include <iostream>
using namespace std;

int main(){
  
  int D,N;
  
  cin >> D >> N;
  if(D == 0 && N < 100)cout << N*1;
  if(D == 0 && N == 100)cout << 101;
  if(D == 1 && N < 100)cout << N*100;
  if(D == 1 && N == 100)cout << 101*100;
  if(D == 2 && N < 100)cout << N*10000;
  if(D == 2 && N == 100)cout << 101*10000;
  
  return 0;
}
  
