#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if( a == min(a,min(b,c)) ){
      
      cout << max(b,c)-a << endl;
    }
  
  else if( b==min(a,min(b,c)) ){
    
      cout << max(a,c)-b << endl;
    }
  
    else if( c==min(a,min(b,c)) ){
      
      cout << max(a,b)-c << endl;
      
    }
      
}
