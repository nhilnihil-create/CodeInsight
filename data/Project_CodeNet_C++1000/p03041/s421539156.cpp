#include <bits/stdc++.h>
using namespace std;

int main(){
  
  int a,b;
  string s;
  cin >> a >> b >> s; 
  
  b--;
  
  if( s.at(b) == 'A' ){
    
    s.at(b) = 'a';
    
  }
  
  else if( s.at(b) == 'B' ){
    
    s.at(b) = 'b';
    
  }
  
  else if( s.at(b) == 'C' ){
    
    s.at(b) = 'c';
    
  }
  
    cout << s << endl;
  
}
