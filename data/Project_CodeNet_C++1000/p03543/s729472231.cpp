#include<bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  int a, b, c, d;
  
  a = n / 1000;
  b = n % 1000 / 100;
  c = n % 1000 % 100 / 10;
  d = n % 1000 % 100 % 10 /1;
    
    if (a == b && b == c && c == d){
      cout << "Yes" << endl;
    }
    
    else if (a == b && a == c){
      cout << "Yes" << endl;
    }
    else if(b == c && b == d){
      cout << "Yes" << endl;
    }
    else{
      cout << "No" << endl;
    }
}
  
      
