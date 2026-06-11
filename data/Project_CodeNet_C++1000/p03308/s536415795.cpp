#include <iostream>
using namespace std;

int main(){
  int i, n, min=2000000000, max=0, tmp;
  cin >> n;
  
  for( i=0; i<n; i++ ){
  	cin >> tmp;
    if( tmp < min ){
      min = tmp;
    }
    if( tmp > max ){
      max = tmp;
    }
  }
  
  cout << abs(min-max) << endl;
  return 0;
}