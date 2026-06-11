#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int i, n, t, a, tmp, place;
  float min = 1000000.0;
  cin >> n;
  cin >> t >> a;
  
  for( i=0; i<n; i++ ){
  	cin >> tmp;
    if( abs(t-tmp*0.006-a) < min ){
      min = abs(t-tmp*0.006-a);
      place = i;
    }
  }
  
  cout << place+1 << endl;
  return 0;
}