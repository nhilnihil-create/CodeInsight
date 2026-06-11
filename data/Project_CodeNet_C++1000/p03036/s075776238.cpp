#include <bits/stdc++.h>
using namespace std;
using ll=long long;


int main() {
  int a , b , c ;
  cin >> a >> b >> c;
  
  int x=1;
  for(int i=0;i<10;i++){
    x=a*c-b;
    cout <<x <<endl;
    c=x;
  }
    
    
}
    