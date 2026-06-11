#include <bits/stdc++.h>
using namespace std;
 
int64_t lucasSum(int lucas) {
  if(lucas == 0) {
     return 2;
  }
  
  if(lucas == 1) {
    return 1;
  }
  
  // L0,L1を初期値として設定しておく
  int64_t left_side = 2;
  int64_t right_side = 1;
  int64_t sum = 0;
  
  for(int i = 1; i < lucas; i++) {
    	sum = left_side + right_side;
    	left_side = right_side;
        right_side = sum;
  }
  
  return sum;
}
int main() {
  int N;
  cin >> N;
  
  cout << lucasSum(N) << endl;
}

