#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string A, B;
  cin >> A >> B;
  int total = 0;
  
  
  
  int a,b;
  a = atoi(A.c_str());
  b = atoi(B.c_str());
  
  string c;
  c = to_string(a);
  	
  
  for (int i = a; i <= b; i++){
    
    string c;
  	c = to_string(i);
    
    if (c.at(0) == c.at(4)){
      if (c.at(1) == c.at(3)){
        total = total + 1;
      }
    }
    
  }
 
  	cout << total << endl;
 

 }