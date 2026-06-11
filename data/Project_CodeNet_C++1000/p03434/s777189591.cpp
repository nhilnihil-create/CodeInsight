#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; 
  cin >> N;
  vector<int> A(N);
  
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  bool check = true;
  bool changed = false;
  int temp1;
  int temp2;
  
  while(check){
    changed = false;
    for (int i = 0; i < N - 1; i++){
      if (A.at(i) < A.at(i+1)){
        temp1 = A.at(i);
        temp2 = A.at(i+1);
        A.at(i) = temp2;
        A.at(i+1) = temp1;
        changed = true;
      }
    }
    
    if (changed == false){
      check = false;
    }
  }
  
  int ans = 0;
  
  for (int i = 0; i < N; i++){
    if (i % 2 == 0){
      ans += A.at(i);
    }
    else{
      ans -= A.at(i);
    }
  }
  
  cout << ans << endl;
  
}
