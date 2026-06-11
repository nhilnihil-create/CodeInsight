#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string N;
  cin >> N;
  char tmp=N[0];
  int counter = 1;
  int max_count = 1;
  
  
  for(int i=1; i<4; i++){
    if (tmp==N[i]){
      counter++;
      if (max_count<counter){
        max_count = counter;
      }
    }
    else{
      counter = 1;
    }
    tmp = N[i];
  }
  
  if (max_count>=3){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}