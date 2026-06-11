#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>vec(N);
  for (int i=0; i < N; i++){
  cin >> vec.at(i);
  }
  
  for (int i = 0; i < N; i++){
    bool a = true;
    
  for (int j = i+1; j < N;j++){
  if (vec.at(i) == vec.at(j)){
  vec.at(i) = 0;
    a = false;
    continue;
    
  }  
  }
   if(a){
   vec.at(i) = 1;
   }  
  }
  
  int b = 0;
  
  for (int i=0; i < N; i++){
  b = b + vec.at(i);
  }
  
  cout << b << endl;
  
}
 