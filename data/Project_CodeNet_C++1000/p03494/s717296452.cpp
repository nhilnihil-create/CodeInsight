#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int A[200];
  
  int mim=10000000000;
  
    for (int j=0;j<N;j++) {
      cin >> A[j];
      int times=0;
      
      while (A[j] % 2 == 0) {
        A[j] /= 2;
        times++;  
      }
      
      if (times < mim) {
       mim = times; 
      }
    }
  cout << mim << endl;
}