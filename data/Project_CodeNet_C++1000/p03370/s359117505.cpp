#include <iostream>
using namespace std;

int main(){
  int i, n, x, min = 2000;
  cin >> n >> x;

  int m[n];
  for( i=0; i<n; i++ ){
    cin >> m[i];
	x -= m[i];
    if( m[i] < min ){
      min = m[i];
    }
  }    
  cout << n+x/min << endl;
  return 0;
}
