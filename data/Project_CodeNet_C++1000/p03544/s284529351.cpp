#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N = 0;
  int64_t L0 = 2;
  int64_t L1 = 1;
  int64_t L2 = 0;
  cin >> N;
 
  // 配列のサイズ-1回だけループしたい
  for (int i = 0; i < N-1; i++) {
    L2 = L1 + L0;
    L0 = L1;
    L1 = L2;
  }
  if(N == 0){
    cout << L0 << endl;
  }else if(N == 1){
  	cout << L1 << endl;
  }else{
  	cout << L2 << endl;
  }
}