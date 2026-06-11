#include <bits/stdc++.h>
using  namespace std;

int main(){
  
  string N;
  cin >> N;
  
  if(N.at(0) == N.at(1) && N.at(1) == N.at(2) && N.at(2) ==N.at(0)){
    
    cout << "Yes" << endl;;
  }
  else if(N.at(1) == N.at(2) && N.at(2) == N.at(3) && N.at(3) == N.at(1)){
    
    cout << "Yes" << endl;
  }
  
  else{
    cout << "No" << endl;
  
  }
  
}
