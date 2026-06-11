#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  long long A[200];
  int count = 0;
  long long keep = 0;
  cin >> N; // input()
  
  for(int i = 0; i < N; ++i) cin >> A[i];
  
  while(true){
    for(int i = 0; i < N; ++i){
      keep = A[i]%2;
      if(keep == 1){
        break;
      }
      A[i] = A[i]/2;
    }
    if(keep == 1){
        break;
    }
    count++;
  }
  cout << count <<endl; // output()
}