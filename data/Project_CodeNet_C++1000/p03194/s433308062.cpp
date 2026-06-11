#include <iostream>
#include <math.h>
using namespace std;

int main(){
  long long int n, p, ans;
  cin >> n >> p;

  ans = pow( (long double)p, 1.0/(long double)n) + 1;
  while(ans > 1){
    if ( p % ( long long int)pow( (long long int)ans, (long long int)n ) == 0 ){
      break;
    }else{
      ans --;
    }
  }
  cout << ans << endl;
}