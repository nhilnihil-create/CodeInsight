#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; ++i) cin >> A[i];
  bitset<4000001> bit = 0;
  bit[0] = 1;
  int s = 0;
  for(int i = 0; i < N; ++i){
    bit |= (bit<<A[i]);
    s += A[i];
  }
  for(int i = (s+1)/2; i <= s; ++i){
    if(bit[i]){
      cout << i << endl;
      return 0;
    }
  }
}
