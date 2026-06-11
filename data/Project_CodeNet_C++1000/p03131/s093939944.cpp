#include <iostream>
using namespace std;

int main(){
  long long k, a, b;
  cin >> k >> a >> b;
  if(b-a>2){
    if(a-1+2<=k){
     long long sum = 0;
      k -= a-1+2;
      sum += b;
      sum += (b-a)*(k/2);
      sum += k%2;
      cout << sum << endl;
    }else{
      cout << k+1 << endl;
    }
  }else{
    cout << k+1 << endl;
  }
  return 0;
}