#include <bits/stdc++.h>
using namespace std;

int main() {
  
  long long x,y,a;
  cin >> x >> y;
  
  a = x;
  
  int cnt = 1;
  
  while(a <= y){
    a *= 2;
    //cout << a << endl;
    if ( a <= y ){
      cnt++;
    }
    //cout << cnt << endl;
  }
  
  cout << cnt << endl;   
 
}