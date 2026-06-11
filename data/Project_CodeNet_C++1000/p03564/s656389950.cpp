#include<bits/stdc++.h>
using namespace std;

int main(void){
  int n, k, a = 1;
  cin >> n >> k;
  
  for( int i = 0 ; i < n ; i++ ) {
    int b;
    b = a*2 - a;
    if( b <= k ){
	  a *= 2;
    }
    else{
      a += k;
    }
    //cout << a << endl;
  }
  cout << a << endl;
}