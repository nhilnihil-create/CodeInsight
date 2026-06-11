#include <bits/stdc++.h>
using namespace std;

bool is_integer( double x ){
  return floor(x)==x;
}

bool Check(int n){
    
   if(n == 1) return true;
   if(n == 1000) return true;
   else for(int i=2;i<=10;i++) if(is_integer(pow(n,1.0/i))) return true;
   return false;
}

int main(void){
    
    int X;
    cin >> X;
    for(int i=X;i>=1;i--){
        if(Check(i)) {
            cout << i << endl;
            return 0;   
        }
    }
}