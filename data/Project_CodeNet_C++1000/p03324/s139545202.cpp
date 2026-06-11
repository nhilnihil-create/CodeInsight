#include <bits/stdc++.h>
using namespace std;

int main() {
  int d , n;
  cin >> d >> n;
  if ( d == 0 ) {
    if ( n!= 100) {
    cout << n << endl;
    }else cout << 101 << endl;
    return 0 ;
  }else if ( d == 1 ){
    if ( n!=100){
    cout << n*100 << endl;
    }else cout << 10100 <<endl;
    return 0;    
  }else if ( d==2){
    if ( n!= 100){
    cout << n*10000 << endl;
    }else cout << 1010000 << endl;
  }
}