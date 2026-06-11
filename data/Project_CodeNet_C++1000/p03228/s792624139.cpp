#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main(void){
  int k,i;
  ll a,b;
  
  cin >> a >> b >> k;
  
  for (i=0;i<k;i++){
    if (i%2==0){
      b+=a/2;
      a/=2;
    }else{
      a+=b/2;
      b/=2;
    }
  }
  
  cout << a << ' ' << b << endl;
  
  return 0;
}