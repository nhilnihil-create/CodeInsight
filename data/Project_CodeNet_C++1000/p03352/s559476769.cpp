#include <bits/stdc++.h>
using namespace std;

int main() {
  int x ;
  cin >> x;
  vector <bool> a(x+1,false);
  if ( x <=3){
    cout << 1 << endl;
    return 0;
  }
  for ( int i=2 ; i<=x ; i++){
    int v = i*i ; 
    for ( int j=2 ; j<=10 ; j++){
      if ( v > x){
        continue ;
      }else if ( v <=x){
        a.at(v)=true;
        v*=i;
      }
    }
  }
  for ( int i =x ; i>0 ; i--){
    if(a.at(i)) {
      cout << i<< endl;
      return 0 ;
    }
  }
}