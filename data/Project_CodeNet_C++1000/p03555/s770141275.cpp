#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  string A, B;
  cin >> A;
  cin >> B;
  
  int count = 0;
  
  for(int i = 0; i < 3; i++){
    if(A.at(i) == B.at(2 - i)){
      count++;
    }
  }
  
  if(count == 3){
    cout << "YES" << endl;
  }
  
  else{
    cout << "NO" << endl;
  }
}